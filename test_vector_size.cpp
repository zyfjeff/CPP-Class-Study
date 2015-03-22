/*
 =====================================================================================
        Filename:  test_vector_size.cpp
     	Description:  
        Version:  1.0
        Created:  12/03/15 00:33:54
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{

	vector<int> vt(20);
	cout << "max_size:"<<vt.max_size() << endl;
	cout << "size:"<<vt.size() << endl;
	cout << "capacity:"<<vt.capacity() << endl;
	vt.push_back(6);
	cout << "max_size:"<<vt.max_size() << endl;
	cout << "size:"<<vt.size() << endl;
	cout << "capacity:"<<vt.capacity() << endl;
	
	vt.reserve(100); //预分配空间
	cout << "size:"<<vt.size() << endl;
	cout << "capacity:"<<vt.capacity() << endl;
	
	vt.resize(200,0);
	cout << "size:"<<vt.size() << endl;
	cout << "capacity:"<<vt.capacity() << endl;
}
