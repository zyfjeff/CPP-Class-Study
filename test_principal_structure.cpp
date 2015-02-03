/*
 *	测试委托构造
 *
 */ 

#include <iostream>

using namespace std;

class person
{

public:
	person(int num):data(num){};
	person()
	{
		person(0);
	}
public:
	int data;
};


int main()
{
	person zhang;
	cout << zhang.data << endl; //不是0,person(0)不是在构造的时候调用的，所以data(num)没有执行
}
