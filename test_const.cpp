/*
 =====================================================================================
        Filename:  test_const.cpp
     	Description:  
        Version:  1.0
        Created:  01/03/15 16:35:10
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
using namespace std;

void test(int (&arr)[10])
{
	for(auto ch : arr)
		cout << ch << endl;
}
int main()
{
	int a = 9;
	int b[] = {1,2,34};
	int c[] = {1,2,3,4,5,6,7,8,9,10};
//	test(&a); // 错误
//	test(b); //错误，元素个数不够
	test(c); //OK
}
