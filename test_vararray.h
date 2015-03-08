#ifndef   ARRAY_CLASS  
#define   ARRAY_CLASS  
 
#include   <iostream>  
#include   <stdlib.h>  
using namespace std;
 
#ifndef   NULL  
const   int   NULL   =   0;  
#endif
 
enum ErrorType  
{invalidArraySize,   memoryAllocationError,   indexOutOfRange};  
 
static char *errorMsg[]   =  
{  
    "Invalid   array   size",   "Memory   allocation   error",  
    "Invalid   index:   "  
};  
 
 
template <class T>  
class Array  
{  
private:  
    // a   dynamically   allocated   list   containing   size   items  
    //一个动态申请的包含size个元素的表  
    T*     alist;  
    int   size;  
 
    //error   handling   method  
    //出错处理函数  
    void   Error(ErrorType   error,int badIndex=0)   const;  
 
public:  
    //constructors   and   destructor  
    Array(int   sz   =   2);  
    Array(const   Array<T>&   A);  
    ~Array(void);  
 
    //assignment,   indexing   and   pointer   conversion  
    //赋值,下标,和指针转换操作  
    Array<T>&   operator=   (const   Array<T>&   rhs);  
    T&   operator[](int   i);  
    operator   T*   (void)   const;  
 
    //   size   operations  
    //有关表大小的函数  
    int   ListSize(void)   const;       //   read   the   size  
    void   Resize(int   sz);                 //   modify   the   size  
};  
 
//   prints   the   message   corresponding   to   error  
template   <class   T>  
void   Array<T>::Error(ErrorType   error,   int   badIndex)   const  
{  
    cerr   <<   errorMsg[error];  
    //   for   indexOutOfRange,   print   the   bad   index  
    if   (error   ==   indexOutOfRange)  
        cerr   <<   badIndex;  
    cerr   <<   endl;  
    exit(1);  
}  
 
//   constructor  
template   <class   T>  
Array<T>::Array(int   sz)  
{  
    //   check   for   an   invalid   size   parameter  
    //检查数组大小参数是否合法  
    if   (sz   <   0)   //我把改为sz<0  
        Error(invalidArraySize);  
    //   assign   the   size   and   dynamically   allocate   memory  
    //给size赋值并动态申请内存  
    size   =   sz;  
    alist   =   new   T[size];          
    //   make   sure   that   system   allocates   the   desired   memory,    
    //确保系统分配了所需的内存  
    if   (alist   ==   NULL)  
        Error(memoryAllocationError);  
}  
 
//   destructor  
template   <class   T>  
Array<T>::~Array(void)  
{    
    delete   []   alist;  
}  
 
//copy   constructor  
//拷贝构造函数  
template   <class   T>  
Array<T>::Array(const   Array<T>&   X)  
{  
    //   get   size   from   object   X   and   assign   to   current   object  
    //取得对象X的大小并将其赋值给当前对象    
    int   n   =   X.size;  
 
    size   =   n;  
 
    //   allocate   new   memory   for   object   and   do   error   checking  
    //为对象申请新内存并进行出错检查  
    alist   =   new   T[n];                       //   allocate   dynamic   array  
    if   (alist   ==   NULL)  
        Error(memoryAllocationError);  
 
    //   copy   array   items   from   x   to   current   object  
    //从X中拷贝数组元素到当前对象      
    T*   srcptr   =   X.alist;         //   address   at   start   of   X.alist  
    T*   destptr   =   alist;           //   address   at   start   of   alist  
    while   (n--)                           //   copy   list  
        *destptr++   =   *srcptr++;  
}  
 
//assignment   operator.   assign   rhs   to   the   current   object  
//赋值rhs给当前对象  
template   <class   T>  
Array<T>&   Array<T>::operator=   (const   Array<T>&   rhs)  
{  
    //   record   the   size   of   rhs记录rhs的大小  
    int   n   =   rhs.size;  
    //   if   sizes   not   the   same,   delete   memory   and   reallocate  
    //如果大小不相同，删除并重新分配内存  
    if   (size   !=   n)  
    {  
        delete   []   alist;                 //   destroy   original   memory  
        alist   =   new   T[n];               //   allocate   a   new   array  
        if   (alist   ==   NULL)  
            Error(memoryAllocationError);  
        size   =   n;  
    }  
    //   copy   array   items   from   rhs   to   current   object  
    //   拷贝rhs到当前对象  
    T*   destptr   =   alist;//T*为重载运算符，返回数组首地址  
    T*   srcptr   =   rhs.alist;  
    while   (n--)  
        *destptr++   =   *srcptr++;  
    //   return   reference   to   the   current   object  
    return   *this;  
}  
 
//   overloaded   index   operator  
//重载下标运算符  
template   <class   T>  
T&   Array<T>::operator[](int   n)  
{  
    //   do   array   bounds   checking  
    //数据越界检查  
    if   (n   <   0   ||   n   >   size-1)  
        Error(indexOutOfRange,n);  
    //   return   the   element   from   the   private   array   list  
    //从私有数级中返回元素值  
    return   alist[n];  
}  
 
//   pointer   conversion   operator  
template   <class   T>  
Array<T>::operator   T*   (void)   const  
{  
    //   return   address   of   private   array   in   the   current   object  
    //返回当前对象中私有数组的首地址  
    return   alist;  
}  
 
template   <class   T>  
int   Array<T>::ListSize(void)   const  
{  
    return   size;  
}  
 
//   resize   operator  
template   <class   T>  
void   Array<T>::Resize(int   sz)  
{  
    //   test   new   size   parameter;   terminate   if   size   <=   0  
    //检查新的大小参数;若其小于等于0,则退出程序  
    if   (sz   <   0)//原来为sz<=0，我把它改为sz<0，因为在V中目录下会出现0个文件  
        Error(invalidArraySize);  
    //   nothing   to   do   if   size   hasn't   changed  
    //若大小不变,则简单返回  
    if   (sz   ==   size)  
        return;  
 
    //   request   new   memory   and   verify   system   response  
    //需申请新的内存;确认系统已分配所需内存  
    T*   newlist   =   new   T[sz];  
    if   (newlist   ==   NULL)  
        Error(memoryAllocationError);  
 
    //   declare   n   with   value   sz   (truncating   list)  
    //   or   otherwise   declare   n   to   be   the   current   size  
    //n为需拷贝元素的个数  
    int   n   =   (sz   <=   size)   ?   sz   :   size;  
 
    //   copy   n   array   items   from   old   to   new   memory  
    //从旧表中拷贝n个数组元素到新表  
    T*   srcptr   =   alist;             //alist的首地址address   at   start   of   alist  
    T*   destptr   =   newlist;       //   newlist首地址address   at   start   of   newlist  
    while   (n--)                           //   拷贝表元素copy   list  
        *destptr++   =   *srcptr++;  
 
    //   delete   old   list删除旧表  
    delete[]   alist;  
 
    //   reset   alist   to   point   at   newlist   and   update   the   size  
    //将alist指针指向newlist并改变大小值  
    alist   =   newlist;  
    size   =   sz;  
}  
 
#endif     //   ARRAY_CLASS  
