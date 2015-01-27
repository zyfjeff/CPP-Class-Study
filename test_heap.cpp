/*
 * 堆操作:
 * make_heap(_First, _Last, _Comp)
 * push_heap (_First, _Last)
 * pop_heap(_First, _Last)
 * sort_heap(_First, _Last)
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <functional>

using namespace std;

void PrintfVectorInt(vector<int> &vet)  
{  
    for (vector<int>::iterator pos = vet.begin(); pos != vet.end(); pos++)  
 		cout << *pos << endl;   
}  


int main()
{
    const int MAXN = 20;  
    int a[MAXN];  
    int i;  
    for (i = 0; i < MAXN; ++i)  
        a[i] = rand() % (MAXN * 2);  

    //动态申请vector 并对vector建堆
    vector<int> *pvet = new vector<int>(40);  
    pvet->assign(a, a + MAXN);
   
    //建立堆
    make_heap(pvet->begin(), pvet->end());  
    PrintfVectorInt(*pvet);
  
    //加入新数据,现在容器加入，然后放入堆中
    pvet->push_back(25);  
    push_heap(pvet->begin(), pvet->end());  
//    PrintfVectorInt(*pvet);  	

    // 删除数据 要先调用pop_heap()  再在容器中删除
    pop_heap(pvet->begin(), pvet->end());  
    pvet->pop_back();  
    pop_heap(pvet->begin(), pvet->end());  
    pvet->pop_back();  
//    PrintfVectorInt(*pvet);  
  
    //堆排序
    sort_heap(pvet->begin(), pvet->end());  
//    PrintfVectorInt(*pvet);  
  
    delete pvet;  
    return 0;
}
