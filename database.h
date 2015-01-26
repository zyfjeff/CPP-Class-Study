/**************
* File Name: database.h
* Author: Jeff
* Purpose: header file for database.cpp class
**************/
#ifndef DATABASE_H
#define DATABASE_H

#include <mysql/mysql.h>

/**************
* Database Error Definitions
**************/
#define SUCCESS 200
#define ERR201 201
#define ERR202 202
#define ERR203 203
#define MAX_QUERY_LEN 500

class database
{
 public:
typedef void (*deal)(MYSQL_ROW row,int);
 //class constructor
 database();

 //connection & disconnect
 int       openConnection(const char *host,const char *db, const char *user,const char *pass); //connect to the database
 bool      disconnect(); //disconnect from the database

 //querying
 bool Query(const char *query); //return result set
 bool Insert(const char *query); 
 int Update(const char *query);
 int Delete(const char *query); 
 bool free();
 int Getfieldcount(const char *tbname);
 void DealData(deal,int fieldcount);

 private:
 MYSQL *sock;
 MYSQL_RES *result;
 MYSQL_ROW row;
 MYSQL_FIELD *field;
};

const char *dberror(int errorcode); //return a string for this error message

#endif
