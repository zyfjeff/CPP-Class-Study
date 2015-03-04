/*
 =====================================================================================
        Filename:  test_auto.cpp
     	Description:  测试auto
        Version:  1.0
        Created:  27/02/15 22:28:38
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>


int main()
{
	int i = 0;
	int &r = i;
	auto a = r;
	a = 10;
	std::cout << i << std::endl;
}
