#ifndef STORAGE_H
#define STORAGE_H

#include<list>

typedef struct _storage{
     int sid;
	   char* name;
	   char* addr;
	   int score1,score2,score3;
	   }storage;
	   
typedef list<storage> storage_list;

void load();
void save();


#endif
