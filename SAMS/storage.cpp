#include"storage.h"

#include<cstdlib>
#include<fstream>
#include<iostream>
 

using namespace std;

void swap(STUDENT* a,STUDENT* b){
	STUDENT t=*a;
	*a=*b;
	*b=t;
}
void qs(STUDENT* s,int begin,int end,int flag)
{
	switch (flag)
	{
	case SORT_BY_SID:
	{
		int compare=s[begin].sid, left =begin,right = end;
		if(left >right)
			return;
		while (left <right)
		{
			while ((left <right) && s[right].sid>=compare)
				right--;

			swap(&s[left],&s[right]);
			while ((left <right) &&(s[left].sid <compare))
				left++;

			swap(&s[right],&s[left]);
		}
		s[right] = s[left];
		qs(s,begin,right-1,flag);
		qs(s,right+1,end,flag);
	}
		break;

	case SORT_BY_TOTAL:
	{
		int compare=s[begin].score_total, left =begin,right = end;
		if(left >right)
			return;
		while (left <right)
		{
			while ((left <right) && s[right].score_total>=compare)
				right--;

			swap(&s[left],&s[right]);
			while ((left <right) &&(s[left].score_total <compare))
				left++;

			swap(&s[right],&s[left]);
		}
		s[right] = s[left];
		qs(s,begin,right-1,flag);
		qs(s,right+1,end,flag);
	}
		break;

	case SORT_BY_MATH:
	{
		int compare=s[begin].score_math, left =begin,right = end;
		if(left >right)
			return;
		while (left <right)
		{
			while ((left <right) && s[right].score_math>=compare)
				right--;

			swap(&s[left],&s[right]);
			while ((left <right) &&(s[left].score_math <compare))
				left++;

			swap(&s[right],&s[left]);
		}
		s[right] = s[left];
		qs(s,begin,right-1,flag);
		qs(s,right+1,end,flag);
	}
		break;

		case SORT_BY_ENG:
		{
		int compare=s[begin].score_eng, left =begin,right = end;
		if(left >right)
			return;
		while (left <right)
		{
			while ((left <right) && s[right].score_eng>=compare)
				right--;

			swap(&s[left],&s[right]);
			while ((left <right) &&(s[left].score_eng <compare))
				left++;

			swap(&s[right],&s[left]);
		}
		s[right] = s[left];
		qs(s,begin,right-1,flag);
		qs(s,right+1,end,flag);
		}
		break;

		case SORT_BY_COM:
		{
		int compare=s[begin].score_com, left =begin,right = end;
		if(left >right)
			return;
		while (left <right)
		{
			while ((left <right) && s[right].score_com >=compare)
				right--;

			swap(&s[left],&s[right]);
			while ((left <right) &&(s[left].score_com <compare))
				left++;

			swap(&s[right],&s[left]);
		}
		s[right] = s[left];
		qs(s,begin,right-1,flag);
		qs(s,right+1,end,flag);
		}
		break;

	default:
		break;
	}
}

bool addData(STUDENT s){
	if(last_student==MAX_STUDENT)return false;
	students[++last_student]=s;
	return true;
}

int nextData(int begin){
	int index=begin;
	while(++index<=last_student){
		if(students[index].sid!=0)return index;
	}
	return 0;
}

bool delData(int id){
	if(id<0||id>last_student)return false;
	//把最后一个元素移动到要删除的元素这里覆盖
	int index=findData(id);
	if(index&&last_student)students[index]=students[last_student];
	students[last_student].sid=0;
	last_student--;
	return true;

/*
	//这里想多了
	for(int i=1;i<=last_student;i++){
		if(students[i].sid==0){
			index=nextData(i);
			if(index!=0){
				students[i]=students[index];
				students[index].sid=0;
		}
	}
*/
}

int findData(int id){
	if(id<0||id>last_student)return 0;
	int i=0;
	while(i<=last_student){
		if(students[++i].sid==id)return i;
	}
	return 0;
}

int findData(int id,int begin){
	if(id<0||id>last_student)return 0;
	int i=begin;
	while(i<=last_student){
		if(students[++i].sid==id)return i;
	}
	return 0;
}

void showData(bool flag){
	if(flag){
		for(int i=1;i<=last_student;i++){
			cout<<i<<'\t';
			printData(i);
		}
	}
	else
	{
		for(int i=last_student;i>=1;i--){
			cout<<i<<'\t';
			printData(i);
		}
	}
}

void showDataWithTotal(bool flag){
	if(flag){
		for(int i=1;i<=last_student;i++){
			cout<<i<<'\t';
			printDataWithTotal(i);
		}
	}
	else
	{
		for(int i=last_student;i>=1;i--){
			cout<<i<<'\t';
			printDataWithTotal(i);
		}
	}
}

void printData(int id){
	if(id<0||id>last_student)return;
	STUDENT &s=students[id];
	cout<<s.name<<'\t'<<s.sid<<'\t'<<s.addr<<'\t'<<s.score_math<<'\t'<<s.score_eng<<'\t'<<s.score_com<<endl;
}

void printDataWithTotal(int id){
	if(id<0||id>last_student)return;
	STUDENT &s=students[id];
	cout<<s.name<<'\t'<<s.sid<<'\t'<<s.addr<<'\t'<<s.score_math<<'\t'<<s.score_eng<<'\t'<<s.score_com<<'\t'<<s.score_total<<endl;
}

void sortBySID(){
	qs(students,1,last_student,SORT_BY_SID);
}

void sortByTotal(){
	qs(students,1,last_student,SORT_BY_TOTAL);
}

void sortByAny(int flag){
	qs(students,1,last_student,flag);
}

bool saveData(){
	ofstream ofile("data.bin",ios::binary);
	if(ofile==NULL)return false;
	ofile.write((char*)&last_student,sizeof(last_student));
	ofile.write((char*)&students[1],sizeof(STUDENT)*(last_student));
	ofile.close();
	return true;
}

bool loadData(){
	ifstream ifile("data.bin",ios::binary);
	if(ifile==NULL)return false;
	ifile.read((char*)&last_student,sizeof(last_student));
	ifile.read((char*)&students[1],sizeof(STUDENT)*(last_student));
	ifile.close();
	return true;
}