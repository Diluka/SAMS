#ifndef STORAGE_H
#define STORAGE_H

#include<map>
using namespace std;

typedef struct _student{
		int sid;
	   char* name;
	   char* addr;
	   int score_math,score_eng,score_com;
	   }student;
	   
typedef int student_id;
typedef map<student_id,student> student_map;

bool load();
bool save();


#endif
