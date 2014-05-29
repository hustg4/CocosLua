#!/bin/sh

projName=$1
projPath=$2

#(1)拷贝模板工程
`rm -rf "${projPath}/${projName}"`
`cp -r "template" ${projPath}`

`mv "${projPath}/template" "${projPath}/${projName}"`

#(2)修改项目名称
export LC_COLLATE='C'
export LC_CTYPE='C'
sed -i.bak "s/template/${projName}/g" `grep template -rl ${projPath}/${projName}`
find "${projPath}/${projName}" -name *.bak | xargs rm -fr

path=`pwd`
cd "${projPath}/${projName}"
find . -name template*|sed "s/\(.*\)\(template\)\(.*\)/mv \1\2\3 \1${projName}\3/"|sh
cd "${path}"

#(3)拷贝框架

frameworkPath="${projPath}/${projName}/framework"

`mkdir ${frameworkPath}`
`cp -r "../../frameworks" ${frameworkPath}`
`cp -r "../../runtime" ${frameworkPath}`

