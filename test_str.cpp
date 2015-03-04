/*
 =====================================================================================
        Filename:  test_str.cpp
     	Description:  
        Version:  1.0
        Created:  01/03/15 01:41:51
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <cstring>
#include <iostream>

using namespace std;
int main()
{
	char ca[] = {'c','+'};
	const char *cb = "c++";
	cout << strlen(ca) << endl;
}
