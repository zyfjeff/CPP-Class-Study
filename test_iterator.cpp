/*
 =====================================================================================
        Filename:  test_iterator.cpp
     	Description:  a
        Version:  1.0
        Created:  15/03/15 11:59:56
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <iterator>
using namespace std;


int main()
{
	istream_iterator<int> int_it(cin);
	istream_iterator<int> eof; //尾迭代器
	
	while(int_it != eof)
	{
		cout << *int_it << endl;
		int_it++;
	}
	cout << "end" << endl;
}
