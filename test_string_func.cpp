/*
 =====================================================================================
        Filename:  test_string_func.cpp
     	Description:  测试字符串相关的操作
        Version:  1.0
        Created:  12/03/15 00:58:32
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <string>

using namespace std;


int main()
{
	const char *cp = "hello wordl";
	char buf[] = {'a','e'}; //不是以空字符结束
	string s1(cp); //const char* 构造
	string s2(s1); //string构造
//	string s3(buf); //存在问题.结果是未定义的。

	//求子串
	cout << s1.substr(0,4) << endl;
	
	//插入
	cout << s1.insert(3,"zhang") << endl;
	
	//删除
	cout << s1.erase(0,10) << endl;

	//赋值
	cout << s1.assign("test") << endl;
	
	//追加
	cout << s1.append("wang") << endl;

	//替换
	cout << s1.replace(1,5,"zzzz") << endl;
}
