#ifndef STORAGE_H
#define STORAGE_H

#include<map>
using namespace std;

typedef struct _student{
		int sid;
	   char* name;
	   char* addr;
	   int score1,score2,score3;
	   }student;
	   
typedef int student_id;
typedef map<student_id,student> student_map;

void load();
void save();


#endif
