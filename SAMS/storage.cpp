#include<iostream>
#include"storage.h"
#include<fstream>
#include<string>
extern student_map sdata;
bool load(){
	ifstream rfile("sdata.txt");
	if(!rfile)
		 return false;
	student temp_s;
	while(!rfile.eof()){
		rfile>>temp_s.name>>temp_s.sid>>temp_s.addr>>temp_s.score_math>>temp_s.score_eng>>temp_s.score_com;
		sdata[temp_s.sid]=temp_s;
	
	}
	rfile.close();
   return true;
	 }
	 
bool save(){
	 ofstream wfile("sdata.txt");
	 if(!wfile)
		 return false; 
	for(student_map::iterator iter=sdata.begin();iter!=sdata.end();iter++){
		wfile<<(*iter).second.name<<' '<<(*iter).first<<' '<<(*iter).second.addr<<' '<<(*iter).second.score_math<<' '<<(*iter).second.score_eng<<' '<<(*iter).second.score_com<<endl;
	}
	wfile.close();
	 return true;
	 }
