#include <iostream>

/*
 *	交换两个数的方法
 *
 */ 

using namespace std;
int main()
{

	int a = 10,b = 20;
//方法一
	a = a + b;
	b = a - b;
	a = a - b;
	cout << a <<"\t"<< b<< endl;

//方法二
	a = a^b;
	b = a^b;
	a = a^b;

	cout << a <<"\t"<< b<< endl;
}
