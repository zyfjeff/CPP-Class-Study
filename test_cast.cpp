/*
 =====================================================================================
        Filename:  test_cast.cpp
     	Description:  显示类型转换
        Version:  1.0
        Created:  01/03/15 08:37:37
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

};

class man
{
	
};

int main()
{
	double value = 4.5;
	//两种转换基本一致
	int value2 = static_cast<int>(value);	 //C++
	int value3 = (int)value;//C 风格
	
	//安全提升
	person *ap;
	man *am;
	am = (man*)ap; //C风格，没有提示错误	

	am = static_cast<man*>(ap); //提示类型不同,错误
	
}
