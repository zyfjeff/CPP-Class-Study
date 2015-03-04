/*
 =====================================================================================
        Filename:  uuid.cpp
     	Description:  获取uuid
        Version:  1.0
        Created:  27/02/15 15:43:32
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <uuid/uuid.h>
#include <stdio.h>

int main()
{
	uuid_t uu;
	uuid_generate(uu);
	std::cout << uu << std::endl;
	for(int i = 0;i < 16;i++)
	{
		printf("%x ",uu[i]);
	}
	printf("\n");
}
