#ifndef STORAGE_H
#define STORAGE_H

#include<string>
#include<map>
using namespace std;

typedef int student_id;

typedef struct _student{
		student_id sid;
	   string name;
	   string addr;
	   int score_math,score_eng,score_com;
	   }student;
	   

typedef map<student_id,student> student_map;

bool load();
bool save();


#endif
