#ifndef STORAGE_H
#define STORAGE_H
typedef struct _storage{
     int sid;
	   char* name;
	   char* addr;
	   int score1,score2,score3;
	   _storage* next;
	   _storage* forward;
	   }storage;
	   
void load();
void save();


#endif
