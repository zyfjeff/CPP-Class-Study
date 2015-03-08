/*
 =====================================================================================
        Filename:  test_class.cpp
     	Description:  测试常量成员函数
        Version:  1.0
        Created:  04/03/15 17:19:16
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>

using namespace std;

class person
{
public:
	const person &print_const()const
	{
		cout << zhang << endl;
		return *this;
	}
	void print()
	{
		cout << "test" << endl;
	}
	private:
		int zhang = 4;
};

int main()
{
	const person ab;
	ab.print_const();
}
