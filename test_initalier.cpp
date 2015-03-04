/*
 =====================================================================================
        Filename:  test_initalier.cpp
     	Description:  可变参数
        Version:  1.0
        Created:  04/03/15 01:40:17
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>

using namespace std;

void test(initializer_list<string> li)
{
	for(auto beg = li.begin(); beg != li.end();++beg)
		cout << *beg << " ";
	cout << endl;
}

int main()
{
	test({"xzhswdcw","xwsxwqxw","sw2axs"});
}
