#include "database.h"
#include <iostream>

using namespace std;


void cb_func(MYSQL_ROW row,int fieldname)
{
	for(int i = 0;i < fieldname;i++)
	{
		cout << row[i]<<"\t";
	}
	cout << endl;
}

int main()
{
	database mydb;
	mydb.openConnection("127.0.0.1","mysql","root","server");
	const char *sql = "use mysql";
	mydb.Query(sql);
	//查询某个表有多少列
	cout << mydb.Getfieldcount("user") << endl;
	/*
 
		mydb.Update(sql);
		mydb.Insert(sql);
		mydb.Delete(sql);
	 */
	//处理数据
	mydb.DealData(cb_func,mydb.Getfieldcount("user"));
}

