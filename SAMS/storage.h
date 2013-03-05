#ifndef STORAGE_H
#define STORAGE_H

#include<map>
using namespace std;

typedef struct _storage{
		int sid;
	   char* name;
	   char* addr;
	   int score1,score2,score3;
	   }storage;
	   
typedef map<int,storage> storage_map;

void load();
void save();


#endif
