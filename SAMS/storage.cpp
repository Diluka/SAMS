#include<iostream>
#include"storage.h"
#include<fstream>
extern student_map sdata;
bool load(){
	ifstream rfile("sdata.txt");
	if(!rfile)
		 return false;
	student temp_s;
	

   return true;
	 }
	 
bool save(){
	 ofstream wfile("sdata.txt");
	 if(!wfile)
		 return false; 
	for(student_map::iterator iter=sdata.begin();iter!=sdata.end();iter++){
		wfile<<(*iter).second.name<<' '<<(*iter).first<<' '<<(*iter).second.addr<<" "<<(*iter).second.score_math<<' '<<(*iter).second.score_eng<<' '<<(*iter).second.score_com<<endl;
	}
	wfile.close();
	 return true;
	 }
