#!/bin/sh

scriptPath="/Users/wangpeng/Public/develop/workspace/xcode/9c/dwx/DWX/DWX/Resources/script"

targetPath="/Users/wangpeng/Public/develop/workspace/xcode/9c/dwx/DWX/DWX/Resources/script2"

luacPath="/Users/wangpeng/Public/resource/lua/lua-5.1.5/src/luac"

echo "================================"

function compileLua(){

    local filePath=$1
    local targetPath=$2

    #判断给定路径是文件还是文件夹
    if [ -d "$filePath" ]; then
        echo "path:[${filePath}]"
        echo "targetPath:[${targetPath}]"

        #检查targetPath是否存在，如果不存在则创建
        if [ ! -d "${targetPath}" ]; then
            mkdir "${targetPath}"
        fi

        #遍历文件夹并递归
        local filelist=`ls ${filePath}`
        for file in $filelist
        do
            compileLua "${filePath}/${file}" "${targetPath}/${file}"
        done

    else
        #编译lua文件
        echo "file:[${filePath}]"
        echo "targetFile:[${targetPath}]"
        `${luacPath} -o ${targetPath} ${filePath}`
    fi
}

compileLua "${scriptPath}" "${targetPath}"
