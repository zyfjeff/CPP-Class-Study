/*
 =====================================================================================
        Filename:  test_struct.cpp
     	Description:  而是委托构造函数
        Version:  1.0
        Created:  04/03/15 16:13:27
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <string>

using namespace std;
class person
{
	public:
		person(const string name,int age,bool sex):Name(name),Age(age),Sex(sex){}
		person(const string name):person(name,22,false){}
	private:
	const sting Name;
	int Age;
	bool Sex;
}

int main()
{


}
