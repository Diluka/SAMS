#include<time.h>
#include<iostream>
#include<stdlib.h>
#include"storage.h"
#include"module2.h"

using namespace std;

void initialize(){
   extern student_map sdata;//在main中全局定义 
	 load();
	 /* TODO (#1#): 未完成 */
	 
	 }
	 
void welcome(){
	 system("cls");
	 time_t t=time(0);
	 char time_s[64];
	 strftime(time_s,sizeof(time_s),"%a %b %d %H:%M:%S %Y",localtime(&t));
	 cout<<" 版权所有：Diluka，Kevin"<<endl;
	 cout<<endl;
	 cout<<" 学生成绩管理系统"<<endl;
	 cout<<" 显示系统时间和日期："<<time_s<<endl;
	 cout<<endl;
	 cout<<"1.输入添加学生资料"<<endl;
	 cout<<"2.显示学生资料"<<endl;
	 cout<<"3.按学号查找"<<endl;
	 cout<<"4.删除记录"<<endl;
	 cout<<"5.按总分进行排序"<<endl;
	 cout<<"6.退出"<<endl;
	 cout<<"请选择操作(1-6)"<<endl;
	 }

char first_face(){
	 initialize();
	 welcome();

	 char ch=getchar();
	 while(1){
		 switch(ch){
		 			case'1':break;
		 			case'2':in_storage();break;
		 			case'3':select_ele();break;
		 			case'4':out_storage();break;
		 			case'5':break;
		 			case'6':exit(0);
		 			default:welcome();
					}
		ch=getchar();
				}
	 return '?';
	 }
