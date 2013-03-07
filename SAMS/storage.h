#ifndef STORAGE_H
#define STORAGE_H

#define MAX_STUDENT 65536
#define MAX_LENTH_OF_STR 16
#define SORT_BY_SID 1
#define SORT_BY_TOTAL 2
#define SORT_BY_MATH 3
#define SORT_BY_ENG 4
#define SORT_BY_COM 5

typedef struct STUDENT
{
	int sid;
	char name[MAX_LENTH_OF_STR];
	char addr[MAX_LENTH_OF_STR];
	int score_math;
	int score_eng;
	int score_com;
	int score_total;
}STUDENT;

//SID等于0说明该项为空，所有学号均不为0

static STUDENT students[MAX_STUDENT];
static int last_student=0;
//不使用0号元素，方便if语句判定

bool addData(STUDENT s);
bool delData(int id);
int findData(int id);
int findData(int id,int begin);
int nextData(int begin);
void printData(int id);
void printDataWithTotal(int id);
void showData(bool flag);
void showDataWithTotal(bool flag);
void sortBySID();
void sortByTotal();
void sortByAny(int flag);
bool saveData();
bool loadData();

#endif
