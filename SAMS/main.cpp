#include <cstdlib>
#include <iostream>
#include<time.h>
#include"functional.h"
#include"storage.h"

student_map sdata;//全局变量存储学生成绩表

using namespace std;

void initialize(){ 
	 if(!load()){//读取文件
		 //读取失败需要进行的处理
		 //TODO
	 }
	 
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

int main(int argc, char *argv[])
{
   initialize();
	 welcome();

	 char ch=getchar();
	 while(1){//无限循环，直到用户退出
		 switch(ch){
		 			case'1':addRecord();break;
		 			case'2':dspRecord();break;
		 			case'3':searchBySid();break;
		 			case'4':delRecord();break;
		 			case'5':orderByScore();break;
		 			case'6':if(!save()){
						//退出时保存，失败之后要进行的处理
						//TODO
							}
							exit(0);
		 			default:welcome();
					}
		ch=getchar();
				}
    system("PAUSE");
    return EXIT_SUCCESS;
}
