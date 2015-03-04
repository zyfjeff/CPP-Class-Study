/*
 =====================================================================================
        Filename:  test_return.cpp
     	Description:  测试局部对象返回
        Version:  1.0
        Created:  04/03/15 02:26:43
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <string>

using namespace std;

const string &test_return()
{
	string ret = "zhangyifei";
	if(!ret.empty())
		return ret;
	else
		return "Empty";
}

int main()
{
	test_return();
}
