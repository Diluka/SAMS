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
}
void searchBySid(){
}
void delRecord(){
}
void orderByScore(){
}