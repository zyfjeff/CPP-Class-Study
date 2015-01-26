/*
 =======================================================
 Name		:	 mysql.c
 Author		:	 Jeff
 Version	:	 1.0
 Description	:	 Connect to mysql
 =======================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>	
#include <mysql/mysql.h>
#include <stdlib.h>

MYSQL mysql, *connection;

int main()
{
	//初始化mysql资源 socket
	mysql_init(&mysql);

	//连接mysql 资源句柄,host,user,password,dbname,portnumber,unix_socket_name,flags
	connection = mysql_real_connect(&mysql,"127.0.0.1","root","server","mysql",0,0,0);
	if(connection == NULL)
	{
		//错误处理,返回错误详细信息
		printf("connect error,%s\n",mysql_error(&mysql));
		//错误处理，返回错误码
		printf("connect error code:%d\n",mysql_errno(&mysql));
		exit(1);
	}
	//设置字符集
	if(mysql_query(connection,"SET NAMES utf8") != 0)
	{
		printf("设置字符集错误,%s\n",mysql_error(&mysql));
	}
	printf("MySQL Connect Success\n");

	//增删改查语句
	printf("==========================================\n");
	//查询语句select
	char *SQL = "select * from user";
	if(mysql_query(connection,SQL) != 0)
	{
		printf("query error, %s\n",mysql_error(&mysql));
		exit(-1);
	}
	//存储查询到的结果
	MYSQL_RES *result = mysql_store_result(connection);
	//存放字段信息
	MYSQL_FIELD *field;
	int fieldcount = 0;
	while(1)
	{
		field = mysql_fetch_field(result);//得到列名
		if(field == NULL)
			break;
		printf("field: %s\n",field->name);
		//统计列数
		fieldcount++;
	}
	//循环遍历每一行
	//存放每一条记录，变为一个数组,每一个元素是相应字段的值
	MYSQL_ROW row;
	while(1)
	{
		row = mysql_fetch_row(result);
		if(row == NULL)
			break;
		int i = 0;
		for(;i < fieldcount;i++)
		{
			printf("%s\t",(const char*)row[i]);
		}
		printf("\n");
	}
	//释放结果集
	mysql_free_result(result);	
	
	//插入语句 mysql_query 成功返回0，失败返回1
	//删除语句 mysql_query 成功返回0，失败返回1 mysql_affected_rows获取受影响的行数
	//update语句 同上
	
	printf("MySQL Query Success\n");
	
	//关闭连接
	mysql_close(connection);

	
}
