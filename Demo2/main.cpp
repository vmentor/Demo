#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
 
int k=10;
using namespace std;
string BOMTable[100][2];
string AltBOMTable[100][2];
bool done[100];
int counnt=0;	// BOMtable資料數 
int total=0;	// 物件總數 

//for test
bool LoopDetector(int);
string print2(string,int,int);
string strr(string s){
	return s;
}
int Plus(int a, int b)

{

       return a + b;

}
int T1(int a)
{
	return a;
}

 

//test function

TEST(Print2Test, FTest)

{
	ASSERT_EQ("A", print2(BOMTable[1][0],1,0));
	ASSERT_EQ("+-B+-B1(Alt)", print2(BOMTable[1][1],1,1));
}
TEST(Test2,QTest)
{
	EXPECT_EQ(4,T1(4));

} 

//toTEST1
string print2(string father,int flag,int level){
	string output="";
	for(int j=1;j<level;j++){
		cout << "  ";
		output += "  ";
	}
	if(level>0){
		cout << "+-";
		output += "+-";
	}
	cout << father;
	output += father;
	
	
	for(int i=0;i<counnt;i++){
		if(AltBOMTable[i][0]==father){
			cout << "+-" << AltBOMTable[i][1] << "(Alt)";
			output += "+-" + AltBOMTable[i][1] + "(Alt)";
		}
	}
	cout << endl;
	for(int i=flag;i<total;i++){
		if(BOMTable[i][0]==father){
			if(LoopDetector(i)){
				for(int j=0;j<level;j++)
					cout << "  ";
				cout << "+-" << father << "(loop)" << endl;
			}else{
				/*****/
				string buffer = print2(BOMTable[i][1],i,level+1);
			}
			
		}
	}
	return output;
}
//toTest2
bool LoopDetector(int flag){
	if ( BOMTable[flag][0]==BOMTable[flag][1])
		return true;
	else
		return false;
}

//main funtion

int main(int argc, char **argv)

{
	fstream files;
	char c[100];
	char* chim=",";
	//char* a[100];
	string buffer;

	files.open("BOMTable.txt",ios::in);
	if(!files)
		cout << "open fail!\r\n";

	do{
		
		files.getline(c,sizeof(c));
		
		buffer.assign(c);
		cout <<buffer <<endl;
		stringstream ss(buffer);
		string tmpstr = ss.str;
		if(!strcmp(tmpstr.c_str,"\r\n'"))
		 break;
		getline(ss,BOMTable[total][0],','); //以,為分隔 
        getline(ss,BOMTable[total][1],',');
		total++;
		
	}while(!files.eof());
	files.close();
	cout << "已關閉檔案1" << endl;
	system("pause");
	/***********file2************/
	fstream file2;
	file2.open("AltBOMTable.txt",ios::in);
	if(!file2){
		cout << "fail" <<endl;
		system("pause");
	}
	
	do{
		file2.getline(c,sizeof(c));
		buffer.assign(c);
		stringstream ss(buffer);
		string tmpstr = ss.str;
		if (!strcmp(tmpstr.c_str, "\r\n'")) {
			cout << "error\r\n";
			break;
		}
		getline(ss,AltBOMTable[counnt][0],','); //以,為分隔 
        getline(ss,AltBOMTable[counnt][1],',');
		counnt++;
		cout << "目前counnt=" << counnt <<endl;
		
		//cout << "count" << count << endl;
		if(!file2.eof())
			cout << "over!!!" <<endl;
	}while(!file2.eof());
	file2.close();
	cout << "結果" << counnt <<endl;
	
	cout << "正式表格"<<endl;
	buffer = print2(BOMTable[1][0],1,0);
	buffer = print2(BOMTable[5][0],5,0);
	system("pause");


	std::cout << "Running main() from gtest_main,cc\n";
	testing::InitGoogleTest(&argc, argv);
	int x=RUN_ALL_TESTS();
	system("pause");
	return 0;
	system("pause");
	   

}