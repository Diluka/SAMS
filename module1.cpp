#include<time.h>
#include<iostream>
#include<stdlib.h>
#include"storage.h"

using namespace std;

void initialize(){
   extern storage sdata;//��main��ȫ�ֶ��� 
	 load();
	 //TODO
	 }
	 
void welcome(){
	 system("cls");
	 time_t t=time(0);
	 char time_s[64];
	 strftime(time_s,sizeof(time_s),"%a %b %d %H:%M:%S %Y",localtime(&t));
	 cout<<" ��Ȩ���У�Diluka��Kevin"<<endl;
	 cout<<endl;
	 cout<<" ѧ���ɼ�����ϵͳ"<<endl;
	 cout<<" ��ʾϵͳʱ������ڣ�"<<time_s<<endl;
	 cout<<endl;
	 cout<<"1.�������ѧ������"<<endl;
	 cout<<"2.��ʾѧ������"<<endl;
	 cout<<"3.��ѧ�Ų���"<<endl;
	 cout<<"4.ɾ����¼"<<endl;
	 cout<<"5.���ֽܷ�������"<<endl;
	 cout<<"6.�˳�"<<endl;
	 cout<<"��ѡ�����(1-6)"<<endl;
	 }

char first_face(){
	 initialize();
	 welcome();

	 char ch=getchar();
	 while(1){
		 switch(ch){
		 			case'1':break;
		 			case'2':break;
		 			case'3':break;
		 			case'4':break;
		 			case'5':break;
		 			case'6':exit(0);
		 			default:welcome();
					}
		ch=getchar();
				}
	 return '?';
	 }
