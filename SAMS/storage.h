#ifndef STORAGE_H
#define STORAGE_H


using namespace std;

typedef struct STUDENT_INFO
{
	int sid;
	char* name;
	char* addr;
	int score_math;
	int score_eng;
	int score_com;
	int score_total;
};

typedef struct STUDENT{
	   struct STUDENT_INFO info;
	   struct STUDENT *next,*prev;
	   }STUDENT;

STUDENT student_list;
STUDENT* student_head;

void init();
bool load();
bool save();
STUDENT* create(STUDENT_INFO &info);
bool insert(register STUDENT **ps,STUDENT &s);
void erase(STUDENT *ptr);
STUDENT* search(STUDENT *head,int id);
void freelist(STUDENT *head);
void print(STUDENT *head);


#endif
