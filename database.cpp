/**************
* File Name: database.cpp
* Author: Design1online.com, LLC
* Purpose: mysql database class
**************/
#include "database.h"
#include <iostream>
#include <strings.h>
#include <cstdio>
#include <mysql/mysql.h>

/**************
* Purpose: default constructor, initialize class values
* Precondition: none
* Postcondition: none
**************/
database::database()
{
 //initilize the mysql fields
 sock = NULL;
 row = NULL;
 result = NULL;
 field = NULL;          
}

/**************
* Purpose: connect to the appropriate database
* Precondition: host, database, user name and password
* Postcondition: connected to that database
**************/
int database::openConnection(const char *host, const char *db, const char *user, const char *pass)
{
 if (sock) //already connected to another database
 disconnect(); //disconnect from that one

 //initilize the socket
 sock = mysql_init(0);

 //something went wrong with the socket
 if (!sock)
 return ERR201;

 //try connecting to the database  
 if (!mysql_real_connect(sock, host, user, pass, db, 0, NULL, 0))
 return ERR202;

 //successfully connected to the database    
 return SUCCESS;  
}

/**************
* Purpose: disconnect from the database
* Precondition: none
* Postcondition: socket closed
**************/
bool database::disconnect()
{
 if (sock) //they have a socket open
 mysql_close(sock);

 //release result data
 free(); 

 //database disconnected
 return true;
}

/**************
* Purpose: free the results from the database query
* Precondition: none
* Postcondition: results no longer there
**************/
bool database::free()
{
 if (result)
 {
  mysql_free_result(result);
  result = NULL;
  return true;
 }

 return false;
}

/**************
* Purpose: return the approprite error message
* Precondition: error code
* Postcondition: string with the error returned
**************/
const char *dberror(int errorcode)
{

 //display the appropriate error message for this error    
 switch(errorcode)
 {
 case SUCCESS: return "SUCCESS";
 break;

 case ERR201: return "201 SOCKET ERROR: SOCKET FAILURE";
 break;

 case ERR202: return "202 CONNECTION ERROR: CANNOT ACCESS THE SERVER";
 break;

 case ERR203: return "203 DATABASE ERROR: QUERY FAILED";
 break;
 }

 return NULL; //no error, return null
}

/**************
* Purpose: return the result set of the query
* Precondition: the query string
**************/
bool database::Query(const char *query)
{        
 //query the database
 if(mysql_query(sock, query) != 0)
	return false;

 //store the results
 result = mysql_store_result(sock);

 return true;

}

/**************
* Purpose: update the database no result returned
* Precondition: the query string
**************/
int database::Update(const char *query)
{        
 if (!mysql_query(sock, query))
	 return -1; //failed query
 else
	 return mysql_affected_rows(sock); //affected row number
}

/**************
* Purpose: insert data
* Precondition: the query string
**************/
bool database::Insert(const char *query)
{
 if(mysql_query(sock,query) != 0)
	return false;
 return true;
}

/**************
* Purpose: delete data
* Precondition: the query string
**************/
int database::Delete(const char *query)
{        
 //query the database
 if(mysql_query(sock,query) != 0)
	return -1;
 else
 	return mysql_affected_rows(sock); //return the id number
}

int database::Getfieldcount(const char *tbname)
{
	char sql[1024];
	bzero(sql,sizeof(sql));
	snprintf(sql,sizeof(sql),"select * from %s",tbname);
	Query(sql);
	if(NULL == result)
		return -1;
	int count  = 0;
	while(1)
        {
           field = mysql_fetch_field(result);//得到列名
           if(field == NULL)
                   break;
	   count++;
	}
	field = NULL;
	return count;
}

void database::DealData(deal cb_func,int fieldcount)
{
    while(1)
        {
                row = mysql_fetch_row(result);
                if(row == NULL)
                        break;
		cb_func(row,fieldcount);
        }
	return;
}

