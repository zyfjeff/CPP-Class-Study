/*
 =====================================================================================
        Filename:  test_var.c
     	Description:   测试可变数组
        Version:  1.0
        Created:  04/03/15 02:07:20
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <stdio.h>
#include <stdarg.h>


void test_var(int size,...)
{
	va_list ap;
	va_start(ap,size);
	while(size > 0)
	{
		int value1 = va_arg(ap,int);
		printf("%d value:%d\n",size,value1);
		size--;
	}

}

int main()
{
	test_var(4,5,6,7,8);
}
