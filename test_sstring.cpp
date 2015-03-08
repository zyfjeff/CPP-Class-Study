/*
 =====================================================================================
        Filename:  test_sstring.cpp
     	Description:  string流的基本使用
        Version:  1.0
        Created:  08/03/15 02:09:48
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	istringstream ss;
	string line;
	string name;
	string phone;
//解析一行，输入 name phone的格式
//解析出name和phone
	while(getline(cin,line))
	{
		ss.str(line);
		ss >> name;	
		ss >> phone;
		cout <<"name:" <<name<< endl;
		cout <<"phone:" <<phone<< endl;
	}
	

	ostringstream so;
	so << name;
	so << "\t";
	so << phone;
	cout << so.str() << endl;
}

