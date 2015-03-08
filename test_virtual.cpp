/*
 =====================================================================================
        Filename:  test_virtual.cpp
     	Description:  测试虚函数表
        Version:  1.0
        Created:  08/03/15 03:15:14
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>

using namespace std;

class Base {

public:
	virtual void f(){cout << "Base::f" << endl;}
	virtual void g(){cout << "Base::g" << endl;}
	virtual void h(){cout << "Base::h" << endl;}

};

class Drive:public Base
{
public:
	virtual void z(){cout << "drived::z" << endl;}
};

typedef void(*fun)(void);

int main()
{
	Base b;
	Drive c;
	fun pfun = NULL;
//	b = &c;
	cout << "虚函数表的地址: " << (int*)(&b) << endl;
	cout << "虚函数表-第一个函数地址: " << (int*)*(int*)(&b) << endl;
	pfun = (fun)*((int*)*(int*)(&b)+1);
	pfun();
	
}

