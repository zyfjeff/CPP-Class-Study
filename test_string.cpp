/*
 =====================================================================================
        Filename:  test_string.cpp
     	Description:  测试字符串
        Version:  1.0
        Created:  28/02/15 04:41:07
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <cstring>
#include <cstdio>

int  main(){

	char s[] = "ab-cd : ef;gh :i-jkl;mnop;qrs-tu: vwx-y;z";
   	char *delim = "-: ";
    	char *p;
	printf("%s ", strtok(s, delim));
        while((p = strtok(NULL, delim)))
        printf("%s ", p);
        printf("\n");
}
