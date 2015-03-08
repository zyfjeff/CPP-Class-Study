/*
 =====================================================================================
        Filename:  test_static_virtual.cpp
     	Description:  
        Version:  1.0
        Created:  08/03/15 23:18:16
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>

using namespace std;

class B
{
public:
 virtual void vfun(int i = 10)
{
	cout << i << endl;	
}
};


class D : public B
{
public:
 void vfun(int i = 20)
{
	cout << i << endl;	
}
};
int main()
{
	D* pD = new D();
	B* pB = pD;
	pD->vfun(); //输出20
	pB->vfun(); //输出20
}
