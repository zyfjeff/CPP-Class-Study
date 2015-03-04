/*
 =====================================================================================
        Filename:  test_const_cast.cpp
     	Description:  测试const_cast
        Version:  1.0
        Created:  04/03/15 10:43:36
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>


using namespace std;


//注意这里是引用，引用没有顶层const的概念，这里是底层const，是可以重载的。
//
//显然无论传入的是string或是const string，最终这个函数的返回结果都是const string
const string &shortstring(const string &s1,const string &s2)
{
	return s1.size() <= s2.size() ? s1:s2;
}
//实现传入的是string则返回的是string的

string &shortstring(string &s1,string &s2)
{
	auto &r = shortstring(const_cast<const string&>(s1),const_cast<const string&>(s2));
	return const_cast<string&>(r);	
}

int main()
{
	
}
