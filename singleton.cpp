/*
 =====================================================================================
        Filename:  singleton.cpp
     	Description:  实现单例模式
        Version:  1.0
        Created:  15/02/15 11:24:09
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>

class Single
{
private:
	Single(){}
public:
	static Single* create()
	{
		if(m_instance)
		{
			m_instance = new Single();
		}
		return m_instance;
	}

private:
	static 	Single *m_instance;
	
};

Single * Single::m_instance = NULL;

int main()
{
//	Single *q = new Single();
	//指向同一个实例
	Single *p = Single::create();
	Single *z = Single::create();
}
