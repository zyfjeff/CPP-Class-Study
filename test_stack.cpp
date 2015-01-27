/*
 *	Study_stack
 *	stack的特性是数据是先进后出，栈只有一个出口，一个入口，只能在栈顶上增加元素，移出元素
 *	STL中栈是以一种容器作为内部的存储结构，在linux的/usr/include/c++/4.8.2/bits/stl_stack.h中定义了
 *	template<typename _Tp, typename _Sequence = deque<_Tp> > 可以看出stack是以deque来作为内部存储数据
 *	结构的。
 *
 */

#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	//可以替换内部的容器为list
	stack<int,list<int> > zhang;
	zhang.push(4);
	zhang.push(5);
	zhang.push(6);
	zhang.push(7);
	zhang.push(8);

	//获取栈顶元素
	cout << zhang.top() << endl;
	
	//弹出栈顶元素
	zhang.pop();
	
	//获取栈的大小
	cout << zhang.size() << endl;
	
	//遍历元素
	while(!zhang.empty())
	{
		cout << zhang.top() << endl;
		zhang.pop();
	}
		
}
