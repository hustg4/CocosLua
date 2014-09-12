#!/bin/sh

PROJ_PATH="/Users/wangpeng/Desktop/soyomaker/proj/framework"

scriptPath="${PROJ_PATH}/frameworks/script"

targetPath="${PROJ_PATH}/frameworks/Resource/script"

luacPath="${PROJ_PATH}/frameworks/cocos2d-x/external/lua/luajit/src/src"

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
        `./luajit -b ${filePath} ${targetPath}`
    fi
}

rm -rf "${targetPath}"
cd "${luacPath}"
compileLua "${scriptPath}" "${targetPath}"
