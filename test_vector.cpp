/*
 =====================================================================================
        Filename:  test_vector.cpp
     	Description:  
        Version:  1.0
        Created:  28/02/15 00:44:30
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
	vector<int> back(100);
	back[0] = 321;
	back.push_back(3213);
	back.push_back(3212);
	back.push_back(3211);
	back.push_back(3210);
	back.push_back(3219);
	back.push_back(3218);
	for(auto data : back)
		cout << data << endl;
}
