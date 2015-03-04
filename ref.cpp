#include <iostream>
#include <utility>
using namespace std;

template <typename T>
void inc(T data)
{
        data++;
}
int main()
{
        int data=0;
        cout << data <<endl;
        inc(data);
        cout << data <<endl; //值还是0没有变，变量的副本机制
        inc(&data);
        cout << data <<endl; //值还是0没有变，&data闯入的是地址
        int &c = data;
        inc(c); //模板是传入引用是无效的
        cout << data <<endl; //值还是0没有变
        //需要传入引用包装器
        inc(ref(data));
        cout << data <<endl; //值还是0没有变
}
