/*
 =====================================================================================
        Filename:  test_copy.cpp
     	Description:  测试拷贝构造函数，赋值构造函数
        Version:  1.0
        Created:  22/03/15 14:14:52
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>

using namespace std;


class base
{
public:
	base(){cout << "I am base struct" <<endl;}
	base(base &data){cout << "I am base copy struct" <<endl;}
	~base(){cout << "I am base destruct" <<endl;}
	base& operator =(const base& data)
	{
		cout << "I am base =="<< endl;
		return *this;
	}
};


class man
{
public:
	man(){cout << "I am man struct" << endl;}
	~man(){cout << "I am man destruct" << endl;}
	man(man& data){cout << "I am man copy struct" << endl;}
	man& operator =(const man& data)
	{
		cout << "I am man =="<< endl;
		return *this;
	}
};

class person:public base
{
public:
	person(){cout << "I am person struct" << endl;}
	person(person& data){cout << "I am person copy struct" << endl;}
	~person() {cout << "I am person destruct" << endl;}
	person& operator =(const person& data)
	{
		cout << "I am person =="<< endl;
		return *this;
	}
private:
	man zhang;
};

void test1(person data)
{
	return ;
}

person test2()
{
	person zhang;
	return zhang;
}

person test3(person data)
{	
	return data;
}

int main()
{

	person zhang;  //默认析构和构造函数
	//构造顺序 base->man->person
	//析构顺序 person->man->base
	cout << "-----------------"<<endl;
	//person wang(zhang);//拷贝构造函数
	//person wang = zhang; 和上面的效果相同
	cout << "-----------------" << endl;
//	person wang;
	cout << "-----------------" << endl;
//	wang = zhang; //调用了赋值构造函数
	cout << "-----------------" << endl;
//	test1(zhang); //调用了拷贝构造函数
	zhang = test2(); // -fno-elide-constructors 进行了优化，省去了一个匿名对象的构造
			 // 返回的时候先生成一个匿名对象，然后拷贝构造，释放函数内部对象，
			 // 用匿名对象赋值构造，最后析构
	
}


