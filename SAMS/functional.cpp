#include<iostream>
#include"storage.h"
using namespace std;

void addRecord(){
	student temp_s;
	char ch;
	do
	{
		cout<<"����������ѧ����������ѧ�ţ���ַ��������Ӣ��������"<<endl;
		cin>>temp_s.name>>temp_s.sid>>temp_s.addr>>temp_s.score_math>>temp_s.score_eng>>temp_s.score_math;
		//TODO
		getchar();//�Ե��س�
		do
		{
			cout<<"�Ƿ�������룿(y/n)";
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