/*
 =====================================================================================
        Filename:  test_dynamic.cpp
     	Description:  动态转换
        Version:  1.0
        Created:  01/03/15 08:57:15
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>

using namespace std;

class base
{
	virtual void test(){}
};

class derived :public base
{	
	
	void test(){}
};

int main()
{
	base *b;
	base bc;
	derived d;
	derived *dc;
	
	b = dynamic_cast<base*>(&d); // 上行转换,derived to base 安全的
	dc  = dynamic_cast<derived*>(&bc); //下行转换 base to derived 需要至少有一个多态函数

}
