#include<iostream>
#include<time.h>
#include"functional.h"
#include"storage.h"


using namespace std;

void initialize(){ 
	 if(!loadData()){
		 cout<<"不能打开文件，读取失败！"<<endl;
		 system("pause");
	 }else{
	 	cout<<"成功加载数据。"<<endl;
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

	 char ch=0;
	 while(ch!='6'){
		 ch=getchar();
		 switch(ch){
		 			case'1':addRecord();break;
		 			case'2':dspRecord();break;
		 			case'3':searchBySid();break;
		 			case'4':delRecord();break;
		 			case'5':orderByScore();break;
		 			case'6':if(!saveData()){
								cout<<"不能打开文件，保存失败！"<<endl;
								cout<<"请检查程序所在目录是否可写后重试。"<<endl;
								system("pause");
								welcome();
								break;
							}else{
								cout<<"保存成功！"<<endl;;
							cout<<"谢谢您的使用！"<<endl;
							system("pause");
							break;
							}
		 			default:welcome();
					}
				}
    return EXIT_SUCCESS;
}
