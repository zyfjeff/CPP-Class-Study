/* 
 *	Study STL->deque
 *	特性: 双向开头的线性空间，可以在头尾两端插入和删除，和vector相似
 *	内部实现原理: 内部维护一块连续区域,这个区域的每一块元素指向另一段较大的区域(用来存放数据)
 *	在这种情况下，如果内部存储区域不够需要重新开辟区域的化，如果是vector就会将原来区域内的数据
 *	重新拷贝到新的区域中，但是要是deque的化就只需要在内部的连续区域中增加一个元素指向一段连续区域即可
 *	所以在这种情况下性能要优于vector.
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
	ideq[1] = 5;
}

