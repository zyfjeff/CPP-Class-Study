/*
 =====================================================================================
        Filename:  test_c++11.cpp
     	Description:  begin and end
        Version:  1.0
        Created:  01/03/15 01:09:05
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>

using namespace std;

int main()
{
	const double zhang = 54.6;
	int b = static_cast<int>(zhang);
	
	int a = 3.12;
	int ia[] = {0,1,2,3,4,5,56,7};
	int *beg = begin(ia);
	int *last = end(ia);
	while(beg != last)
	{
		std::cout << *beg << std::endl;
		beg++;
	}
}
