/*
 =====================================================================================
        Filename:  test_insert.cpp
     	Description:  
        Version:  1.0
        Created:  15/03/15 11:46:10
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> lst = {1,2,3,4};
	list<int> lst2;
	copy(lst.begin(),lst.end(),front_inserter(lst2));
	for_each(lst2.begin(),lst2.end(),[](int c){cout << c << endl; });
}
