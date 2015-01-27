/*
 *	单向队列queue
 *	queue: 和栈类似,栈是同一端入元素和出元素，
 *	queue则是在一端存取元素(队尾)，另一端存入数据(队头).栈是先进后出，队列则是先进先出
 *	queue也是使用别的容器(默认是使用deuqe双端队列最为其内部存储容器)作为内部存储其定义如下:
 *	template<typename _Tp, typename _Sequence = deque<_Tp> >
 *	
 * 	
 */


#include <iostream>
#include <queue>
#include <list>
#include <algorithm>


using namespace std;

int main()
{
	
	//更换内部容器
	queue<int,list<int> > zhang;

	//队列尾部插入数据
	zhang.push(4);
	zhang.push(5);
	zhang.push(6);
	zhang.push(7);

	//返回队列头数据
	cout <<"队列头:"<< zhang.front() << endl;

	//返回队列尾数据
	cout <<"队列尾:"<< zhang.back() << endl;
	
	//队列头返回数据
	zhang.pop();
	
	cout <<"队列头:"<< zhang.front() << endl;
	cout <<"队列尾:"<< zhang.back() << endl;
	
	//判断队列是否返回空
	cout <<"队列是否为空:" <<  zhang.empty() << endl;
	
	//返回队列的数据个数
	cout <<"队列的数据个数:"<< zhang.size() << endl;
	

}
