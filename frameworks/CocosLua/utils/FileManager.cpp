//
//  FileManager.cpp
//  Framework
//
//  Created by wp_g4 on 13-4-23.
//
//

#include "cocos2d.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include <io.h>
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include <unistd.h>
#endif

#include "unzip.h"

#include "FileManager.h"

using namespace std;
using namespace cocos2d;

#define BUFFER_SIZE    8192
#define MAX_FILENAME   512

const char* FileManager::splicePath(const std::string &parentPath, const std::string &childPath)
{
    std::string tempPath1 = parentPath;
    std::string tempPath2 = childPath;
    //��绘��path1���灏剧��'/'
    if (tempPath1.size()>0 && tempPath1.at(tempPath1.size()-1)=='/') {
        tempPath1.erase(tempPath1.size()-1);
    }
    //��绘��path2寮�澶寸��'/'
    if (tempPath2.size()>0 && tempPath2.at(0)=='/') {
        tempPath2.erase(0);
    }
    //��兼��
    std::string path=tempPath1;
    path.append("/");
    path.append(tempPath2);
    return __String::create(path)->getCString();
}

bool FileManager::fileExists(const std::string& filePath)
{
#ifdef _WIN32 
	return ( _access(filePath.c_str(), 0) == 0 ); 
#else 
	return (0 == access(filePath.c_str(), F_OK)); 
#endif 
}

bool FileManager::renameFile(const std::string& oldFilePath, const std::string& newFilePath)
{
    return 0 == rename(oldFilePath.c_str(), newFilePath.c_str());
}

bool FileManager::removeFile(const std::string& filePath)
{
    return 0 == remove(filePath.c_str());
}

bool FileManager::createDirectory(const string& directoryPath)
{
    vector<string> directoryPathArray; // ���瑕����寤虹��褰����璺�寰���扮��
    
    string fullPath = directoryPath.c_str();
    
    //��惧�颁��瀛���ㄧ��褰�锛���惧�ユ�扮��
    string directorySubPath;
    do {
        int pos = fullPath.find_last_of('/');
        directorySubPath = fullPath.substr(0, pos);
        if(!FileManager::fileExists(directorySubPath.c_str())) // ���褰�涓�瀛����
        {
            directoryPathArray.insert(directoryPathArray.begin(), directorySubPath);
            fullPath = directorySubPath.c_str();
        } else
        {
            break;
        }
    } while (true);
    
    // 浠���跺�板�����灞����寤虹��褰�
    bool result = true;
    vector<string>::iterator it = directoryPathArray.begin();
    while (it != directoryPathArray.end()) {
        if(! doCreateDirectory(*it) )
        {
            result = false;
            break;
        }
        it++;
    }
    return result;
}

bool FileManager::doCreateDirectory(const string& directoryPath)
{
    #if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    mode_t processMask = umask(0);
    int ret = mkdir(directoryPath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
    umask(processMask);
    if (ret != 0 && (errno != EEXIST))
    {
        return false;
    }
    
    return true;
    #else
	BOOL ret = CreateDirectoryA(directoryPath.c_str(), NULL);
    	if (!ret && ERROR_ALREADY_EXISTS != GetLastError())
    	{
    		return false;
    	}
        return true;
    #endif
}


bool FileManager::uncompressZipFile(const string &zipFileName, const string &directory)
{
    // Open the zip file
    unzFile zipfile = unzOpen(zipFileName.c_str());
    if (! zipfile)
    {
        CCLOG("can not open downloaded zip file %s", zipFileName.c_str());
        return false;
    }
    
    // Get info about the zip file
    unz_global_info global_info;
    if (unzGetGlobalInfo(zipfile, &global_info) != UNZ_OK)
    {
        CCLOG("can not read file global info of %s", zipFileName.c_str());
        unzClose(zipfile);
    }
    
    // Buffer to hold data read from the zip file
    char readBuffer[BUFFER_SIZE];
    
    CCLOG("start uncompressing %s, to:%s", zipFileName.c_str(), directory.c_str());
    
    // Loop to extract all files.
    uLong i;
    for (i = 0; i < global_info.number_entry; ++i)
    {
        // Get info about current file.
        unz_file_info fileInfo;
        char fileName[MAX_FILENAME];
        if (unzGetCurrentFileInfo(zipfile,
                                  &fileInfo,
                                  fileName,
                                  MAX_FILENAME,
                                  NULL,
                                  0,
                                  NULL,
                                  0) != UNZ_OK)
        {
            CCLOG("can not read file info");
            unzClose(zipfile);
            return false;
        }
        
        // 妫���ユ�����甯�'/'缁�灏�
        string saveToDirectory = directory.c_str();
        if (saveToDirectory[saveToDirectory.size() - 1] != '/') {
            saveToDirectory.append("/");
        }
        string fullPath = saveToDirectory + fileName;
        
        // Check if this entry is a directory or a file.
        const size_t filenameLength = strlen(fileName);
        if (fileName[filenameLength-1] == '/')
        {
            // Entry is a direcotry, so create it.
            // If the directory exists, it will failed scilently.
            if (!createDirectory(fullPath.c_str()))
            {
                CCLOG("can not create directory %s", fullPath.c_str());
                unzClose(zipfile);
                return false;
            }
        }
        else
        {
            // Entry is a file, so extract it.
            
            // Open current file.
            if (unzOpenCurrentFile(zipfile) != UNZ_OK)
            {
                CCLOG("can not open file %s", fileName);
                unzClose(zipfile);
                return false;
            }
            
            // Create a file to store current file.
            FILE *out = fopen(fullPath.c_str(), "wb");
            if (! out)
            {
                CCLOG("can not open destination file %s", fullPath.c_str());
                unzCloseCurrentFile(zipfile);
                unzClose(zipfile);
                return false;
            }
            
            // Write current file content to destinate file.
            int error = UNZ_OK;
            do
            {
                error = unzReadCurrentFile(zipfile, readBuffer, BUFFER_SIZE);
                if (error < 0)
                {
                    CCLOG("can not read zip file %s, error code is %d", fileName, error);
                    unzCloseCurrentFile(zipfile);
                    unzClose(zipfile);
                    return false;
                }
                
                if (error > 0)
                {
                    fwrite(readBuffer, error, 1, out);
                }
            } while(error > 0);
            
            fclose(out);
        }
        
        unzCloseCurrentFile(zipfile);
        
        // Goto next entry listed in the zip file.
        if ((i+1) < global_info.number_entry)
        {
            if (unzGoToNextFile(zipfile) != UNZ_OK)
            {
                CCLOG("can not read next file");
                unzClose(zipfile);
                return false;
            }
        }
    }
    
    CCLOG("end uncompressing");
    
    return true;
}

bool FileManager::writeDataToFile(const unsigned char *content, unsigned long len, const std::string &filePath, bool isAppend)
{    
    const char *mode = isAppend ? "ab" : "wb";
    FILE *fp = fopen(filePath.c_str(), mode); //
    if (! fp)
    {
        CCLOG("���寤烘��浠堕��璇�锛�errno=%d", errno);
        return false;
    }

    size_t written = fwrite(content, len, 1, fp);
    fclose(fp);
    return written == len;
}
