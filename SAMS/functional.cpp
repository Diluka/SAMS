#include<iostream>
#include"storage.h"
#include"functional.h"

using namespace std;

void addRecord(){
	STUDENT temp_s;
	char ch;
	do
	{
		cout<<"请依次输入学生的姓名，学号，地址，高数，英语，计算机："<<endl;
		cin>>temp_s.name>>temp_s.sid>>temp_s.addr>>temp_s.score_math>>temp_s.score_eng>>temp_s.score_com;
		temp_s.score_total=temp_s.score_math+temp_s.score_eng+temp_s.score_com;
		addData(temp_s);
		getchar();//吃掉回车
		do
		{
			cout<<"是否继续输入？(y/n)";
			ch=getchar();
		} while (ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
		
		if(ch=='n'||ch=='N')break;
	}while(ch=='y'||ch=='Y');
	//saveData();

}
void dspRecord(){
	int count=0;
	cout<<"序号\t姓名\t学号\t地址\t高数\t英语\t计算机\t"<<endl;
	sortBySID();
	showData(true);
	system("pause");
}
void searchBySid(){
	int id;
	int index;
	cout<<"请输入您要查找的学号：";
	cin>>id;
	index=findData(id);
	if(index){
		cout<<"查无此人！"<<endl;
	}else{
		cout<<"姓名\t学号\t地址\t高数\t英语\t计算机\t"<<endl;
		printData(index);
	}
	system("pause");
}
void delRecord(){
	int id;
	cout<<"请输入您要删除的学号：";
	cin>>id;
	if(findData(id)){
		cout<<"查无此人！"<<endl;
	}else{
		cout<<"姓名\t学号\t地址\t高数\t英语\t计算机\t"<<endl;
		printData(id);
		cout<<"您确实要删除该学生的记录吗？(y/n)";
		getchar();//吃掉回车
		char ch=getchar();
		if(ch=='y'||ch=='Y'){
			delData(id);
			cout<<"该记录已删除！"<<endl;
			system("pause");
		}
	}
}
void orderByScore(){
	sortByTotal();
	cout<<"序号\t姓名\t学号\t地址\t高数\t英语\t计算机\t总分"<<endl;
	showDataWithTotal(false);
	system("pause");
}
