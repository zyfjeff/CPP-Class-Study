/* 
 *	Study STL->deque
 *
 */	 

#include <iostream>
#include <deque>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	//create  a deque
	deque<int> ideq(20);
	deque<int>::iterator it;
	int i;

	//赋值
	for(i = 0;i < 20;++i)
		ideq[i]  = i; //ideq.assign(i) = i;
	//for_each(ideq.begin(),ideq.end(),[](int data){cout << data <<endl;});

	ideq.assign(20,1); //二十个元素是1
	//for_each(ideq.begin(),ideq.end(),[](int data){cout << data <<endl;});

	//追加数据
	ideq.push_back(100);
	ideq.push_front(111);
//	for_each(ideq.begin(),ideq.end(),[](int data){cout << data <<endl;});

	//查找数据
	it = find(ideq.begin(),ideq.end(),100);
	if(it != ideq.end())
		cout << "find successed" << endl;
	else
		cout << "find failed\n" << endl;

	//头尾删除数据
	ideq.pop_back();
	ideq.pop_front();
//	for_each(ideq.begin(),ideq.end(),[](int data){cout << data <<endl;});
	
	//从中间删除和插入数据
	it = ideq.begin()+6;
	ideq.insert(it,111);
	ideq.insert(it,4,100);
	ideq.erase(it-1);
	for_each(ideq.begin(),ideq.end(),[](int data){cout << data <<endl;});
}

