/*
 =====================================================================================
        Filename:  test_io.cpp
     	Description:  测试IO
        Version:  1.0
        Created:  08/03/15 00:27:30
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream out1,out2;
//	out1 = out2; //错误，不能对流对象赋值
	ofstream print(out1);
}
