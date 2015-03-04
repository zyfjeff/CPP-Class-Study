/*
 =====================================================================================
        Filename:  test_constexpr.cpp
     	Description:  测试常量表达式
        Version:  1.0
        Created:  27/02/15 17:44:27
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>

int a = 213;
int main()
{
	constexpr int *q = &a;
}
