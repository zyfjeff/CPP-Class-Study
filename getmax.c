/*
 *	不适用函数,if ?号表达式 或者switch 求两个数中的最大一个
 *
 */

#include <stdio.h>
#include <math.h>

int main()
{
	int a = 10;
	int b = 20;

	printf("%d\n",((a+b)-abs(a-b))/2);
}
