#include<stdio.h>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;

typedef struct student
{
	string name,gender,sco;
	bool sex;
	double score;
	//student(){};
	//student(string sname;string sgender,string ssco,double ssc):name(sname),gender(sgender),sco(ssco),score(ssc){};
	bool operator <(const student &a) const
	{
		return (score>a.score)||((score==a.score)&&(name<a.name));
	}	
}student;
vector<student>stu;

int main()
{
	freopen("score.csv","r",stdin);
	string line;
	getline(cin,line);
	int count=0;
	string name,gender,sco;
	while(getline(cin,line))
	{	
		student sstu;
		stringstream ss(line);
		getline(ss,name,',');
		getline(ss,gender,',');
		getline(ss,sco,',');
		gender.erase(0,1);sco.erase(0,1);
		//double sc=stod(sco);
		//student sstu(name,gender,sco,sc);
		sstu.name=name;sstu.gender=gender;
		if(sstu.gender=="Male") sstu.sex=true;
		else sstu.sex=false;
		sstu.score=stod(sco);
		stu.push_back(sstu);
	}
	double sall=0;
	double sfemale=0,smale=0;
	int countf=0,countm=0;
	count=stu.size();
	for(int i=0;i<count;++i)
	{
		sall+=stu[i].score;
		if(stu[i].sex) {countm++;smale+=stu[i].score;}
		else {countf++;sfemale+=stu[i].score;}
	}
	sort(stu.begin(),stu.end());
	cout<<"all average: "<<sall/count <<endl;
	cout<<"male average: "<<smale/countm <<endl;
	cout<<"female average: "<<sfemale/countf <<endl;
	for(int i=0;i<count;i++)
	{
		cout<<stu[i].name<<" "<<(stu[i].sex?"Male":"Female")<<" "<<stu[i].score<<endl;
	}		
	return 0;
}
