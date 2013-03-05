#include<iostream>
#include"storage.h"
using namespace std;

void addRecord(){
	student temp_s;
	char ch;
	do
	{
		cout<<"请依次输入学生的姓名，学号，地址，高数，英语，计算机："<<endl;
		cin>>temp_s.name>>temp_s.sid>>temp_s.addr>>temp_s.score_math>>temp_s.score_eng>>temp_s.score_math;
		//TODO
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
	cout<<"序号\t姓名\t学号\t地址\t\t高数\t英语\t计算机\t"<<endl;
}
void searchBySid(){
	cout<<"请输入您要查找的学号：";
}
void delRecord(){
	cout<<"请输入您要删除的学号：";
}
void orderByScore(){
	cout<<"序号\t姓名\t学号\t地址\t\t高数\t英语\t计算机\t"<<endl;
}