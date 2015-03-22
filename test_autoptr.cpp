/*
 =====================================================================================
        Filename:  test_autoptr.cpp
     	Description:  智能指针
        Version:  1.0
        Created:  14/03/15 04:47:38
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */


template <typename T> 
class SmartPointer {

	T *obj;
	unsigned *ref_count;

public:	
	//构造函数,设置智能指针的值.
	SmartPointer(T *object); //设置T *object的值，并引用计数设置为1
	{
		ref = ptr;
		ref_count = (unsigned *)malloc(sizeof(unsigned));
		*ref_count = 1;
	}
	
	//拷贝构造函数,引用计数+1
	SmartPointer(SmartPointer<T> & sptr)
	{
		ref = sptr.ref;
		ref_count = sptr.ref_count;
		++(*ref_count);
	}
	
	SmartPointer<T> &operator=(SmartPointer<T> &sptr)
	{
		if(this == &sptr) return *this;
		if (*ref_count > 0) {
			remove();
		}
		ref = sptr.ref;
		ref_count = sptr.ref_count;
		++(*ref_count);
		return  *this;
	}
	
	//返回其指针
	T getvalue() {
		
		return *ref;
	}
	
	~SmartPointer()
	{
		remove();
	}

protected:
	T *ref;
	unsigned *ref_count;
	void remove() {
		--(*ref_count);
		if(*ref_count == 0) {
		   delete ref;
		   free(ref_count);
		   ref = NULL;
		   ref_count = NULL;
		}
	}
};

