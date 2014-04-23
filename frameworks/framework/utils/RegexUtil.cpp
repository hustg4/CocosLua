//
//  RegexUtil.cpp
//  The9Framework
//
//  Created by wp_g4 on 13-3-19.
//
//

#include "RegexUtil.h"
#include <regex.h>

using namespace std;

//TODO 此函数可使用但有小问题，待改进
int RegexUtil::replaceAll(std::string &str, const std::string &oldStr, const std::string &newStr)
{
    int num=0;
    for(string::size_type pos(0); pos!=string::npos; pos+=newStr.length()) {
        if( (pos=str.find(oldStr,pos))!=string::npos ){
            str.replace(pos,oldStr.length(),newStr);
            num++;
        }else{
            break;
        }
    }
    return num;
}

const char* RegexUtil::search(const std::string &str, const std::string &regex)
{
    regex_t regext;
    int reti;
    char msgbuf[100];
    const int RES_NUM=1;//只可能匹配一个，取决与pattern
    regmatch_t results[RES_NUM];
    string strRes;
    /* Compile regular expression */
    reti = regcomp(&regext, regex.c_str(), REG_EXTENDED);
    if( reti ){ fprintf(stderr, "Could not compile regex\n"); exit(1); }
    
    /* Execute regular expression */
    reti = regexec(&regext, str.c_str(), RES_NUM, results, 0);
    if( !reti ){
        for (int i=0; i<RES_NUM&&results[i].rm_so!=-1; i++) {
            regmatch_t ares=results[i];
            long long s=ares.rm_so;
            long long e=ares.rm_eo;
            strRes.append(str.c_str(), s, e-s);
        }
    }else if( reti != REG_NOMATCH ){
        regerror(reti, &regext, msgbuf, sizeof(msgbuf));
        CCLOG("regex error:%s",msgbuf);
    }
    /* Free compiled regular expression if you want to use the regex_t again */
	regfree(&regext);
    return strRes.size()==0?NULL:cocos2d::__String::create(strRes)->getCString();
}

int RegexUtil::replaceAll(std::string &str, const std::string &regex, cocos2d::Ref *target, RegexUtilReplaceCallBack callback)
{
    int replaceNum=0;
    if (target&&callback) {
        while (true) {
            const char* oldStr=RegexUtil::search(str, regex);
            if (oldStr) {
                const char* newStr=(target->*callback)(oldStr);
                replaceNum+=RegexUtil::replaceAll(str, oldStr, newStr);
            }else{
                break;
            }
        }
    }
    return replaceNum;
}
