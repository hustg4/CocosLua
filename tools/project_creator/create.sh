#!/bin/sh

if [ $# -lt 2 ]; then
echo "error need 2 args\neg:./create.sh Game ~/workspace"
exit 1;
fi

projName=$1
targetPath=$2

if [ ! -x "$targetPath" ]; then
echo "error:target path not exist\neg:./create.sh Game ~/workspace"
exit 1;
fi

#(1)拷贝模板工程
`rm -rf "${targetPath}/${projName}"`
`cp -r "template" ${targetPath}`

`mv "${targetPath}/template" "${targetPath}/${projName}"`

#(2)修改项目名称
export LC_COLLATE='C'
export LC_CTYPE='C'
sed -i.bak "s/template/${projName}/g" `grep template -rl ${targetPath}/${projName}`
find "${targetPath}/${projName}" -name *.bak | xargs rm -fr

path=`pwd`
cd "${targetPath}/${projName}"
find . -name template*|sed "s/\(.*\)\(template\)\(.*\)/mv \1\2\3 \1${projName}\3/"|sh
cd "${path}"

#(3)拷贝框架

frameworkPath="${targetPath}/${projName}/framework"

`mkdir ${frameworkPath}`
`cp -r "../../frameworks" ${frameworkPath}`
`cp -r "../../runtime" ${frameworkPath}`

