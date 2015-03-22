/*
 =====================================================================================
        Filename:  test_destruct_seq.cpp
     	Description:  构造和析构的执行顺序
        Version:  1.0
        Created:  21/03/15 13:46:11
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>

using namespace std;


class A
{
public:
	A(){cout << "I am A struct" << endl;}
	~A(){cout << "I am A destruct" << endl;}
};

class B
{
public:
	B(){cout << "I am B struct" << endl;}
	~B(){cout << "I am B destruct" << endl;}
};

class C:public A
{
public:
	C(){cout << "I am C struct" << endl;}
	~C(){cout << "I am C destruct" << endl;}
private:
	B b;
};

int main()
{
	C c;
}

//输出结果
// 构造顺序
// I am A struct 
// I am B struct
// I am C struct

// 析构顺序
// I am C destruct
// I am B destruct
// I am A destruct
