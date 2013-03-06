#include<iostream>
#include"storage.h"
#include"functional.h"

using namespace std;
extern student_map sdata;

void swap(int *pLeft,int *pRight)
{
int temp;
temp = *pLeft;
*pLeft= *pRight;
*pRight = temp;
}
void qs(int* a,int* b,int begin,int end)
{
int compare=a[begin], left =begin,right = end;
if(left >right)
return;
while (left <right)
{
while ((left <right) && a[right]>=compare)
right--;
//a[left] = a[right];
swap(&a[left],&a[right]);
swap(&b[left],&b[right]);
while ((left <right) &&(a[left] <compare))
left++;
//a[right] = a[left];
swap(&a[right],&a[left]);
swap(&b[left],&b[right]);
}
a[right] = a[left];
qs(a,b,begin,right-1);
qs(a,b,right+1,end);
}



void addRecord(){
	student temp_s;
	char ch;
	do
	{
		cout<<"请依次输入学生的姓名，学号，地址，高数，英语，计算机："<<endl;
		cin>>temp_s.name>>temp_s.sid>>temp_s.addr>>temp_s.score_math>>temp_s.score_eng>>temp_s.score_com;
		sdata[temp_s.sid]=temp_s;
		getchar();//吃掉回车
		do
		{
			cout<<"是否继续输入？(y/n)";
			ch=getchar();
		} while (ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
		
		if(ch=='n'||ch=='N')break;
	}while(ch=='y'||ch=='Y');
	

}
void dspRecord(){
	int count=0;
	cout<<"序号\t姓名\t学号\t地址\t\t高数\t英语\t计算机\t"<<endl;
	for(student_map::iterator iter=sdata.begin();iter!=sdata.end();iter++){
		cout<<++count<<'\t'<<(*iter).second.name<<'\t'<<(*iter).first<<'\t'<<(*iter).second.addr<<"\t\t"<<(*iter).second.score_math<<'\t'<<(*iter).second.score_eng<<'\t'<<(*iter).second.score_com<<endl;
	}
	getchar();
}
void searchBySid(){
	student_id id;
	student_map::iterator iter;
	cout<<"请输入您要查找的学号：";
	cin>>id;
	iter=sdata.find(id);
	if(iter==sdata.end()){
		cout<<"查无此人！"<<endl;
	}else{
		cout<<"姓名\t学号\t地址\t\t高数\t英语\t计算机\t"<<endl;
		cout<<(*iter).second.name<<'\t'<<(*iter).first<<'\t'<<(*iter).second.addr<<"\t\t"<<(*iter).second.score_math<<'\t'<<(*iter).second.score_eng<<'\t'<<(*iter).second.score_com<<endl;
	}
	getchar();
}
void delRecord(){
	student_id id;
	student_map::iterator iter;
	cout<<"请输入您要删除的学号：";
	cin>>id;
	iter=sdata.find(id);
	if(iter==sdata.end()){
		cout<<"查无此人！"<<endl;
	}else{
		cout<<"姓名\t学号\t地址\t\t高数\t英语\t计算机\t"<<endl;
		cout<<(*iter).second.name<<'\t'<<(*iter).first<<'\t'<<(*iter).second.addr<<"\t\t"<<(*iter).second.score_math<<'\t'<<(*iter).second.score_eng<<'\t'<<(*iter).second.score_com<<endl;
		cout<<"您确实要删除该学生的记录吗？(y/n)";
		char ch=getchar();
		if(ch=='y'||ch=='Y'){
			sdata.erase(iter);
			cout<<"该记录已删除！"<<endl;
			getchar();
		}
	}
}
void orderByScore(){
	student_id ida[MAX];
	int sa[MAX];
	int count=0;
	for(student_map::iterator iter=sdata.begin();iter!=sdata.end();iter++){
		ida[count]=(*iter).first;
		sa[count]=(*iter).second.score_math+(*iter).second.score_eng+(*iter).second.score_com;
		count++;
	}
	qs(sa,ida,0,count-1);
	cout<<"姓名\t学号\t地址\t\t高数\t英语\t计算机\t"<<endl;
	for(int i=0;i<count;i++){
		//cout<<"ida: "<<ida[i]<<" sa: "<<sa[i]<<endl;
		cout<<sdata[ida[i]].name<<'\t'<<ida[i]<<'\t'<<sdata[ida[i]].addr<<"\t\t"<<sdata[ida[i]].score_math<<'\t'<<sdata[ida[i]].score_eng<<'\t'<<sdata[ida[i]].score_com<<endl;
	}
	getchar();
}
