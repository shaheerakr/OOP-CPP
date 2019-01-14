#include <iostream>
#include <fstream>
#include <cstring>
#include<math.h>
#include<dos.h>
#include<ctime>
#include<stdlib.h>
#include<conio.h>
#include<ctime>
#include<ctype.h>
#include<windows.h>
#include<process.h>
#include<conio.h>
#include<cstdio>

using namespace std;

/************************************************************ CLASSES ********************************************************************/
class Person;
class Department;
class Courses;
class Student;
class Admin;
class Performance;
class Attendance;
class Teacher;

/******************************************************* FUNCTION PROTOTYPES *************************************************************/
void gotoxy(int , int );
int t(void);
void printLine(char ,int );
void delay(unsigned int);
void printLineSlowly(char ,int ,int);
void printSquareBox(char,int ,int,int,int );
void printTirchaBox(char,int ,int,int,int );
void boxOperation(char l,int height,int width,int x ,int y,void (*functionPtr)(char,int ,int,int,int ));
void printStringSlowly(string , int);
void exit_menu();
void mainmenu_student_admin();
void mainmenu_admin();
void mainmenu_admin_panel();
void mainmenu_students();
bool Password(string );
void clear_Area(int, int, int, int);
void print_thankYou(int , int );
void login();
void logout();
void timetable_design();

/********************************************************* GLOBAL VARIABLES **************************************************************/
const char* password = "FCIT";
const char* username1 = "Imam";
const char* username2 = "Akram";
const char* username3 = "Qadir";
const char* username4 = "Asad";

/************************************************************ DATE CLASS *****************************************************************/
class Date {
	
	int day,month,year;
	string LetterDay;
	public:
		Date();
		void setDay(int);
		void setMonth(int);
		void setYear(int);
		void setLetterDay(string);
		int getDay()const;
		int getMonth()const;
		int getYear()const;
		string getLetterDay()const;
		friend ostream& operator << (ostream & , const Date&);
		//DESTRUCTOR
		~Date();
};

/********************************************************* DATE CLASS FUNCTIONS **********************************************************/
Date::Date():day(0),month(0),year(0),LetterDay("none"){
}
Date::~Date() {
	
}
void Date::setDay(int n){
	if(n<1 ||n>31){
		day=0;	
	}
	else{
		day=n;
	}
}
void Date::setMonth(int n){
	if(n<1 || n>12){
		month=0;	
	}
	else{
		month=n;
	}
}
void Date::setYear(int n){
	if(n<0){
		year=0;	
	}
	else{
		year=n;
	}
}
void Date::setLetterDay(string n){
	LetterDay=n;
}
int Date::getDay()const{
	return day;
}
int Date::getMonth()const{
	return month;
}
int Date::getYear()const{
	return year;
}
string Date::getLetterDay()const{
	return LetterDay;
}
ostream& operator<< (ostream& os , const Date& l){
	os<<l.day<<"-"<<l.month<<"-"<<l.year;
	return os;
}

/********************************************************** DEPARTMENT CLASS ************************************************************/
class Department{
	public:
	void showDetailsME();
	void showAllDetailsME();
	void showDetailsEE();
	void showAllDetailsEE();
	void showDetailsSE();
	void showAllDetailsSE();
	void showDetailsCS();
	void showAllDetailsCS();
	void showDetailsCSE();
	void showAllDetailsCSE();
	void showAttendance();
	void showCourses();	
};

/****************************************************** DEPARTMENT CLASS FUNCTIONS *******************************************************/
void Department::showDetailsME(){
	clear_Area(45,13,115,11);
	string s,si,su,pass,c3,c4;
	int i=13,tag=0,tag1=0;
	ifstream fin1,fin2;
	fin1.open("Mechanical Engineering\\Usernames.txt");
	fin2.open("Mechanical Engineering\\Passwords.txt");
	clear_Area(45,13,115,14);
	gotoxy(45,14);
	cout<<"Enter your username : ";
	cin>>s;
	gotoxy(45,15);
	cout<<"Enter you Password to verify that its you : ";
	cin>>pass;
		while(!fin1.eof() || !fin2.eof()){
			getline(fin1,c3);
			getline(fin2,c4);
			if(s==c3 && pass==c4){
				tag1=1;
				clear_Area(45,13,115,14);
				ifstream fin;
				fin.open("All Details ME\\all details.txt");
				while(!fin.eof()){
					do{
					fin>>si;
					if(si==s){
						tag=1;
						getline(fin,su);
							while(su!="***"){
							gotoxy(45,i++);
							cout<<su<<"\n";
							getline(fin,su);
							}
						}
					break;	
					} 
					while(si!=s);
				}
				fin.close();
			}
		}
	fin1.close();
	fin2.close();
	getch();
	mainmenu_admin_panel();
}
void Department::showDetailsEE(){
	string s,si,su,pass,c3,c4;
	clear_Area(45,13,115,11);
	int i=13,tag=0,tag1=0;
	ifstream fin1,fin2;
	fin1.open("Electrical Engineering\\Usernames.txt");
	fin2.open("Electrical Engineering\\Passwords.txt");
	clear_Area(45,13,115,14);
	gotoxy(45,14);
	cout<<"Enter your username : ";
	cin>>s;
	gotoxy(45,15);
	cout<<"Enter you Password to verify that its you : ";
	cin>>pass;
		while(!fin1.eof() || !fin2.eof()){
			getline(fin1,c3);
			getline(fin2,c4);
			if(s==c3 && pass==c4){
				tag1=1;
				clear_Area(45,13,115,14);
				ifstream fin;
				fin.open("All Details EE\\all details.txt");
				while(!fin.eof()){
					do{
					fin>>si;
					if(si==s){
						tag=1;
						getline(fin,su);
							while(su!="***"){
							gotoxy(45,i++);
							cout<<su<<"\n";
							getline(fin,su);
							}
						}	
					} 
					while(si!=s);
				}
				fin.close();
			}
		}
	fin1.close();
	fin2.close();
	getch();
	mainmenu_admin_panel();
}
void Department::showDetailsSE(){
	clear_Area(45,13,115,11);
	string s,si,su,pass,c3,c4;
	int i=13,tag=0,tag1=0;
	ifstream fin1,fin2;
	fin1.open("Software Engineering\\Usernames.txt");
	fin2.open("Software Engineering\\Passwords.txt");
	clear_Area(45,13,115,14);
	gotoxy(45,14);
	cout<<"Enter your username : ";
	cin>>s;
	gotoxy(45,15);
	cout<<"Enter you Password to verify that its you : ";
	cin>>pass;
		while(!fin1.eof() || !fin2.eof()){
			getline(fin1,c3);
			getline(fin2,c4);
			if(s==c3 && pass==c4){
				tag1=1;
				clear_Area(45,13,115,14);
				ifstream fin;
				fin.open("All Details SE\\all details.txt");
				while(!fin.eof()){
					do{
					fin>>si;
					if(si==s){
						tag=1;
						getline(fin,su);
							while(su!="***"){
							gotoxy(45,i++);
							cout<<su<<"\n";
							getline(fin,su);
							}
						}	
					} 
					while(si!=s);
				}
				fin.close();
			}
		}
	fin1.close();
	fin2.close();
	getch();
	mainmenu_admin_panel();
}
void Department::showDetailsCS(){
	clear_Area(45,13,115,11);
	string s,si,su,pass,c3,c4;
	int i=13,tag=0,tag1=0;
	ifstream fin1,fin2;
	fin1.open("CSIT\\Usernames.txt");
	fin2.open("CSIT\\Passwords.txt");
	clear_Area(45,13,115,14);
	gotoxy(45,14);
	cout<<"Enter your username : ";
	cin>>s;
	gotoxy(45,15);
	cout<<"Enter you Password to verify that its you : ";
	cin>>pass;
		while(!fin1.eof() || !fin2.eof()){
			getline(fin1,c3);
			getline(fin2,c4);
			if(s==c3 && pass==c4){
				tag1=1;
				clear_Area(45,13,115,14);
				ifstream fin;
				fin.open("All Details CS\\all details.txt");
				while(!fin.eof()){
					do{
					fin>>si;
					if(si==s){
						tag=1;
						getline(fin,su);
							while(su!="***"){
							gotoxy(45,i++);
							cout<<su<<"\n";
							getline(fin,su);
							}
						}
					break;	
					} 
					while(si!=s);
				}
				fin.close();
			}
		}
	fin1.close();
	fin2.close();
	getch();
	
}

void Department::showDetailsCSE(){
	clear_Area(45,13,115,11);
	string s,si,su,pass,c3,c4;
	int i=13,tag=0,tag1=0;
	ifstream fin1,fin2;
	fin1.open("CIS\\Usernames.txt");
	fin2.open("CIS\\Passwords.txt");
	clear_Area(45,13,115,14);
	gotoxy(45,14);
	cout<<"Enter your username : ";
	cin>>s;
	gotoxy(45,15);
	cout<<"Enter you Password to verify that its you : ";
	cin>>pass;
		while(!fin1.eof() || !fin2.eof()){
			getline(fin1,c3);
			getline(fin2,c4);
			if(s==c3 && pass==c4){
				tag1=1;
				clear_Area(45,13,115,14);
				ifstream fin;
				fin.open("All Details CSE\\all details.txt");
				while(!fin.eof()){
					do{
					fin>>si;
					if(si==s){
						tag=1;
						getline(fin,su);
							while(su!="***"){
							gotoxy(45,i++);
							cout<<su<<"\n";
							getline(fin,su);
							}
						}	
					} 
					while(si!=s);
				}
				fin.close();
			}
		}
	fin1.close();
	fin2.close();
	getch();
	mainmenu_admin_panel();
}
void Department::showAllDetailsME(){
	int i=13,tag=0,y=15;
	string s1,s2,s3,s4;
	ifstream fin1,fin2;
	fin1.open("Mechanical Engineering\\Usernames.txt");
	fin2.open("Mechanical Engineering\\Passwords.txt");
	clear_Area(45,13,115,11);
	gotoxy(45,13);
	cout<<"USERNAMES: \tPASSWORDS:";
	while(!fin1.eof() || !fin2.eof()){
	getline(fin1,s1);
	getline(fin2,s2);
	gotoxy(45,y);
	cout<<s1;
	gotoxy(65,y);
	cout<<s2;
	y++;
	}
	fin1.close();
	fin2.close();
	gotoxy(45,y);
	cout<<"Press any key to go back . ";
	getch();
	mainmenu_admin_panel();
}
void Department::showAllDetailsEE(){
	int i=13,tag=0,y=15;
	string s1,s2,s3,s4;
	ifstream fin1,fin2;
	fin1.open("Electrical Engineering\\Usernames.txt");
	fin2.open("Electrical Engineering\\Passwords.txt");
	clear_Area(45,13,115,11);
	gotoxy(45,13);
	cout<<"USERNAMES: \tPASSWORDS:";
	while(!fin1.eof() || !fin2.eof()){
	getline(fin1,s1);
	getline(fin2,s2);
	gotoxy(45,y);
	cout<<s1;
	gotoxy(65,y);
	cout<<s2;
	y++;
	}
	fin1.close();
	fin2.close();
	gotoxy(45,y);
	cout<<"Press any key to go back . ";
	getch();
	mainmenu_admin_panel();
}
void Department::showAllDetailsSE(){
	int i=13,tag=0,y=15;
	string s1,s2,s3,s4;
	ifstream fin1,fin2;
	fin1.open("Software Engineering\\Usernames.txt");
	fin2.open("Software Engineering\\Passwords.txt");
	clear_Area(45,13,115,11);
	gotoxy(45,13);
	cout<<"USERNAMES: \tPASSWORDS:";
	while(!fin1.eof() || !fin2.eof()){
	getline(fin1,s1);
	getline(fin2,s2);
	gotoxy(45,y);
	cout<<s1;
	gotoxy(65,y);
	cout<<s2;
	y++;
	}
	fin1.close();
	fin2.close();
	gotoxy(45,y);
	cout<<"Press any key to go back . ";
	getch();
	mainmenu_admin_panel();
}
void Department::showAllDetailsCS(){
	int i=13,tag=0,y=15;
	string s1,s2,s3,s4;
	ifstream fin1,fin2;
	fin1.open("CSIT\\Usernames.txt");
	fin2.open("CSIT\\Passwords.txt");
	clear_Area(45,13,115,11);
	gotoxy(45,13);
	cout<<"USERNAMES: \tPASSWORDS:";
	while(!fin1.eof() || !fin2.eof()){
	getline(fin1,s1);
	getline(fin2,s2);
	gotoxy(45,y);
	cout<<s1;
	gotoxy(65,y);
	cout<<s2;
	y++;
	}
	fin1.close();
	fin2.close();
	gotoxy(45,y);
	cout<<"Press any key to go back . ";
	getch();
	mainmenu_admin_panel();
}
void Department::showAllDetailsCSE(){
	int i=13,tag=0,y=15;
	string s1,s2,s3,s4;
	ifstream fin1,fin2;
	fin1.open("CIS Engineering\\Usernames.txt");
	fin2.open("CIS Engineering\\Passwords.txt");
	clear_Area(45,13,115,11);
	gotoxy(45,13);
	cout<<"USERNAMES: \tPASSWORDS:";
	while(!fin1.eof() || !fin2.eof()){
	getline(fin1,s1);
	getline(fin2,s2);
	gotoxy(45,y);
	cout<<s1;
	gotoxy(65,y);
	cout<<s2;
	y++;
	}
	fin1.close();
	fin2.close();
	gotoxy(45,y);
	cout<<"Press any key to go back . ";
	getch();
	mainmenu_admin_panel();
}

class Courses{
	public:
		void printCSCourses();
		void viewCStable();
		void printMECourseOutline();
		void printEECourseOutline();
		void printSECourseOutline();
		void printCSCourseOutline();
};
void Courses::printCSCourses(){
	clear_Area(45,13,115,11);
	char sub;
	course:
	gotoxy(95,14); cout<<"SELECT COURSE";	
	gotoxy(45,15); cout<<"1.DATA STRUCTURE ALGORITHM AND APPLICATION (CT-157)";	
	gotoxy(45,16); cout<<"2.OBJECT ORIENTED PROGRAMMING (CT-251)";	
	gotoxy(45,17); cout<<"3.DISCRETE STRUCTURE (CT-162)";	
	gotoxy(45,18); cout<<"4.FUNCTIONAL ENGLISH (HS-104)";	
	gotoxy(45,19); cout<<"5.PAKISTAN STUDIES (HS-105)";
	gotoxy(45,20); cout<<"CHOOSE ONE";
	sub=getch();
	switch(sub){
		case '1':
			{
			clear_Area(45,13,115,11);
			gotoxy(45,14); cout<<"1.DATA STRUCTURE ALGORITHM AND APPLICATION (CT-157)";
			gotoxy(45,15); cout<<"Bubble Sort";	
			gotoxy(45,16); cout<<"Stacks";	
			gotoxy(45,17); cout<<"Queues";	
			gotoxy(45,18); cout<<"Linked List";		
				string name;
				ifstream fin;
				gotoxy(45,20); cout << "Enter lecture title : ";
    			getline(cin, name);
				name = "notepad \"" +name+ "\"";
				clear_Area(45,13,115,11);
				gotoxy(45,15); cout<<"Your Lecture Slide is being generated";
				Sleep(4000);
				system((name+".txt").c_str());
				goto course;
			}
		case '2':
			{
			clear_Area(45,13,115,11);
			gotoxy(45,14); cout<<"2.OBJECT ORIENTED PROGRAMMING (CT-251)";
			gotoxy(45,15); cout<<"Classes and Objects";	
			gotoxy(45,16); cout<<"Constructor";	
			gotoxy(45,17); cout<<"Function overloading";	
			gotoxy(45,18); cout<<"Operator overloading";		
				string name;
				ifstream fin;
				gotoxy(45,20); cout << "Enter lecture title : ";
    			getline(cin, name);
				name = "notepad \"" +name+ "\"";
				clear_Area(45,13,115,11);
				gotoxy(45,15); cout<<"Your Lecture Slide is being generated";
				Sleep(4000);
				system((name+".txt").c_str());
				goto course;
			}
		case '3':
			{
			clear_Area(45,13,115,11);
			gotoxy(45,14); cout<<"3.DISCRETE STRUCTURE (CT-162)";
			gotoxy(45,15); cout<<"Logic Gates";	
			gotoxy(45,16); cout<<"Graphs";	
			gotoxy(45,17); cout<<"Tower of Hanoi";	
			gotoxy(45,18); cout<<"Trees";		
				string name;
				ifstream fin;
				gotoxy(45,20); cout << "Enter lecture title : ";
    			getline(cin, name);
				name = "notepad \"" +name+ "\"";
				clear_Area(45,13,115,11);
				gotoxy(45,15); cout<<"Your Lecture Slide is being generated";
				Sleep(4000);
				system((name+".txt").c_str());
				goto course;
			}
		case '4':
			{
			clear_Area(45,13,115,11);
			gotoxy(45,18); cout<<"4.FUNCTIONAL ENGLISH (HS-104)";
			gotoxy(45,15); cout<<"Precis Writing";	
			gotoxy(45,16); cout<<"Idioms";	
			gotoxy(45,17); cout<<"Reading Strategies";	
			gotoxy(45,18); cout<<"Note Taking Strategies";		
				string name;
				ifstream fin;
				gotoxy(45,20); cout << "Enter lecture title : ";
    			getline(cin, name);
				name = "notepad \"" +name+ "\"";
				clear_Area(45,13,115,11);
				gotoxy(45,15); cout<<"Your Lecture Slide is being generated";
				Sleep(4000);
				system((name+".txt").c_str());
				goto course;
			}
		case '5':
			{
			clear_Area(45,13,115,11);
			gotoxy(45,19); cout<<"5.PAKISTAN STUDIES (HS-105)";
			
			}
		default:
			break;
	}
}
void Courses::viewCStable(){
	system("cls");
	int j=45,k=10,i,z=10,v=70,x=46,m=15,a=46;
	char week[5][10]={"MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY"};
	char time[10][15]={"8:30-9:20","9:20-10:10","10:10-11:00","11:00-11:20","11:20-12:10","12:10-01:00","01:00-02:00","02:00-02:50","02:50-3:40","03:40-04:30"};
	gotoxy(j,k);
	for(i=0;i<=110;i++)
	cout<<"|";
	for(i=0;i<=24;i++){
		gotoxy(j,++k); cout<<"|";
	}
	gotoxy(j,35); 
	for(i=0;i<=110;i++){
		cout<<"|";
	}
	for(i=0;i<=24;i++){
	gotoxy(155,++z); cout<<"|";
	}
	gotoxy(46,11); cout<<"SECTION-A";
	gotoxy(46,13); cout<<"TIMING/DAYS";
	for(i=0;i<5;i++){
	 	 gotoxy(v,13); cout<<week[i];
		 v=v+18;
	}
	for(i=0;i<=108;i++){
		gotoxy(x++,14); cout<<"_";
	}
	for(i=0;i<10;i++){
		gotoxy(47,m); cout<<time[i];
		m=m+2;
	}
	for(i=0;i<=108;i++){
		gotoxy(a++,16); cout<<"_";
	}
	a=46;
	for(i=0;i<=108;i++){
		gotoxy(a++,18); cout<<"_";
	}
	a=46;
	for(i=0;i<=108;i++){
		gotoxy(a++,20); cout<<"_";
	}
	a=46;
	for(i=0;i<=108;i++){
		gotoxy(a++,22); cout<<"_";
	}
	a=46;
	for(i=0;i<=108;i++){
		gotoxy(a++,24); cout<<"_";
	}
	a=46;
	for(i=0;i<=108;i++){
		gotoxy(a++,26); cout<<"_";
	}
	a=46;
	for(i=0;i<=108;i++){
		gotoxy(a++,28); cout<<"_";
	}
	a=46;
	for(i=0;i<=108;i++){
		gotoxy(a++,30); cout<<"_";
	}
	a=46;
	for(i=0;i<=108;i++){
		gotoxy(a++,32); cout<<"_";
	}
	gotoxy(45,37); cout<<"Press any key to continue";
	gotoxy(95,8); cout<<"FCIT TIMETABLE";
	gotoxy(70,17); cout<<"DAA(P)(G-1)"; gotoxy(70,19); cout<<"DAA(P)(G-1)"; gotoxy(107,21); cout<<"BREAK"; gotoxy(107,27); cout<<"RECCESS";
	gotoxy(70,23); cout<<"DAA"; gotoxy(70,25); cout<<"DAA"; gotoxy(70,29); cout<<"DAA(P)(G-2)"; gotoxy(70,31); cout<<"DAA(P)(G-2)";
	gotoxy(88,15); cout<<"OOP(P)(G-2)"; gotoxy(88,17); cout<<"OOP(P)(G-2)"; gotoxy(88,23); cout<<"CH"; gotoxy(88,25); cout<<"CH";
	gotoxy(88,29); cout<<"DAA"; gotoxy(88,31); cout<<"ENG"; gotoxy(88,33); cout<<"ENG";
	gotoxy(106,17); cout<<"OOP(P)(G-1)"; gotoxy(106,19); cout<<"OOP(P)(G-1)"; gotoxy(106,23); cout<<"OOP"; gotoxy(88,25); cout<<"ENG"; gotoxy(106,29); cout<<"DS";
	gotoxy(124,17); cout<<"CH"; gotoxy(124,19); cout<<"CH"; gotoxy(124,23); cout<<"DS"; gotoxy(124,25); cout<<"DS";
	gotoxy(142,15); cout<<"PS"; gotoxy(142,17); cout<<"PS"; gotoxy(142,19); cout<<"OOP"; gotoxy(142,23); cout<<"OOP";
	getch();
	system("cls");
}
void Courses::printCSCourseOutline(){
	ifstream fin;
	string name="CScourseoutline";
	name = "notepad \"" +name+ "\"";
	clear_Area(45,13,115,11);
	gotoxy(45,15); cout<<"Your Course Outline is being generated";
	Sleep(4000);
	system((name+".txt").c_str());
}
void Courses::printSECourseOutline(){
	ifstream fin;
	string name="SEcourseoutline";
	name = "notepad \"" +name+ "\"";
	clear_Area(45,13,115,11);
	gotoxy(45,15); cout<<"Your Course Outline is being generated";
	Sleep(4000);
	system((name+".txt").c_str());
}
void Courses::printMECourseOutline(){
	ifstream fin;
	string name="MEcourseoutline";
	name = "notepad \"" +name+ "\"";
	clear_Area(45,13,115,11);
	gotoxy(45,15); cout<<"Your Course Outline is being generated";
	Sleep(4000);
	system((name+".txt").c_str());
}
void Courses::printEECourseOutline(){
	ifstream fin;
	string name="EEcourseoutline";
	name = "notepad \"" +name+ "\"";
	clear_Area(45,13,115,11);
	gotoxy(45,15); cout<<"Your Course Outline is being generated";
	Sleep(4000);
	system((name+".txt").c_str());
}

/************************************************************* PERSON CLASS **************************************************************/
class Person{   // Abstract class. The object of this class cannot be created 
	private:
		string name,address,department,phone,email;
		int age;
	protected:
		Date d_o_b;
	public:
		Person();
		//virtual void functionToMakeItAbstract()=0;
		void setName(string);
		void setAddress(string);
		void setDepartment(string);
		void setPhone(string);
		void setEmail(string);
		void setAge(int);
		string getName()const;
		string getAddress()const;
		string getDepartment()const;
		string getPhone()const;
		string getEmail()const;
		int getAge()const;
		~Person();
};

/********************************************************** PERSON CLASS FUNCTIONS *******************************************************/
Person::Person(){
	name = "none";
	address = "none";
	department = "none";
	phone = "+00-000-0000000";
	email = "none";
	age = 0;
}
Person::~Person(){
	
}
void Person::setName(string name){
	this->name=name;
}
void Person::setAddress(string address){
	this->address=address;
}
void Person::setDepartment(string department){
	this->department=department;
}
void Person::setAge(int age){
	this->age=age;
}
void Person::setPhone(string phone){
	this->phone=phone;
}
string Person::getName()const{
	return name;
}
string Person::getAddress()const{
	return address;
}
string Person::getDepartment()const{
	return department;
}
string Person::getPhone()const{
	return phone;
}
int Person::getAge()const{
	return age;
}

/********************************************************* ATTENDANCE CLASS **************************************************************/
class Attendance{
	
	string c1,c2,c3,c4,c5,c6;
	
	public:
		Attendance();
		void setC1(string);		
		void setC2(string);		
		void setC3(string);		
		void setC4(string);		
		void setC5(string);
		void setC6(string);
		void setC1total(string);
		void setC2total(string);
		void setC3total(string);
		void setC4total(string);
		void setC5total(string);
		void setC6total(string);
		void setC1attendent(string);
		void setC2attendent(string);
		void setC3attendent(string);
		void setC4attendent(string);
		void setC5attendent(string);
		void setC6attendent(string);
		string getC1()const;		
		string getC2()const;		
		string getC3()const;		
		string getC4()const;		
		string getC5()const;		
		string getC6()const;
		void printMEattendance();
		void printEEattendance();
		void printSEattendance();
		void printCSattendance();
		void printCSEattendance();		
		~Attendance();
};

/**************************************************** ATTENDANCE CLASS FUNCTIONS *********************************************************/
Attendance::Attendance(){
	c1 = "none";
	c2 = "none";
	c3 = "none";
	c4 = "none";
	c5 = "none";
}
Attendance::~Attendance(){
	
}
void Attendance::setC1(string x){
	this->c1=x;
}
void Attendance::setC2(string x){
	this->c2=x;
}
void Attendance::setC3(string x){
	this->c3=x;
}
void Attendance::setC4(string x){
	this->c4=x;
}
void Attendance::setC5(string x){
	this->c5=x;
}
void Attendance::setC6(string x){
	this->c6=x;
}
string Attendance::getC1()const{
	return c1;
}
string Attendance::getC2()const{
	return c2;
}
string Attendance::getC3()const{
	return c3;
}
string Attendance::getC4()const{
	return c4;
}
string Attendance::getC5()const{
	return c5;
}
string Attendance::getC6()const{
	return c6;
}
void Attendance::printMEattendance(){
	clear_Area(45,13,115,11);
	string s,si,su,pass,c3,c4;
	int i=13,tag=0,tag1=0;
	ifstream fin1,fin2;
	fin1.open("Mechanical Engineering\\Usernames.txt");
	fin2.open("Mechanical Engineering\\Passwords.txt");
	clear_Area(45,13,115,14);
	gotoxy(45,14);
	cout<<"Enter your username : ";
	cin>>s;
	gotoxy(45,15);
	cout<<"Enter you Password to verify that its you : ";
	cin>>pass;
		while(!fin1.eof() || !fin2.eof()){
			getline(fin1,c3);
			getline(fin2,c4);
			if(s==c3 && pass==c4){
				tag1=1;
				clear_Area(45,13,115,14);
				ifstream fin;
				fin.open("All Details ME\\attendance.txt");
				while(!fin.eof()){
					do{
					fin>>si;
					if(si==s){
						tag=1;
						getline(fin,su);
						while(su!="***"){
						 gotoxy(45,i++);
						 cout<<su<<"\n";
						 getline(fin,su);
						}
						}	
					}while(si!=s);
				}
				fin.close();
			}
		}
	fin1.close();
	fin2.close();
	getch();	
}
void Attendance::printEEattendance(){
	clear_Area(45,13,115,11);
	string s,si,su,pass,c3,c4;
	int i=13,tag=0,tag1=0;
	ifstream fin1,fin2;
	fin1.open("Electrical Engineering\\Usernames.txt");
	fin2.open("Electrical Engineering\\Passwords.txt");
	clear_Area(45,13,115,14);
	gotoxy(45,14);
	cout<<"Enter your username : ";
	cin>>s;
	gotoxy(45,15);
	cout<<"Enter you Password to verify that its you : ";
	cin>>pass;
		while(!fin1.eof() || !fin2.eof()){
			getline(fin1,c3);
			getline(fin2,c4);
			if(s==c3 && pass==c4){
				tag1=1;
				clear_Area(45,13,115,14);
				ifstream fin;
				fin.open("All Details EE\\attendance.txt");
				while(!fin.eof()){
					do{
					fin>>si;
					if(si==s){
						tag=1;
						getline(fin,su);
						while(su!="***"){
						 gotoxy(45,i++);
						 cout<<su<<"\n";
						 getline(fin,su);
						}
						}	
					}while(si!=s);
				}
				fin.close();
			}
		}
	fin1.close();
	fin2.close();
	getch();	
}
void Attendance::printSEattendance(){
	clear_Area(45,13,115,11);
	string s,si,su,pass,c3,c4;
	int i=13,tag=0,tag1=0;
	ifstream fin1,fin2;
	fin1.open("Software Engineering\\Usernames.txt");
	fin2.open("Software Engineering\\Passwords.txt");
	clear_Area(45,13,115,14);
	gotoxy(45,14);
	cout<<"Enter your username : ";
	cin>>s;
	gotoxy(45,15);
	cout<<"Enter you Password to verify that its you : ";
	cin>>pass;
		while(!fin1.eof() || !fin2.eof()){
			getline(fin1,c3);
			getline(fin2,c4);
			if(s==c3 && pass==c4){
				tag1=1;
				clear_Area(45,13,115,14);
				ifstream fin;
				fin.open("All Details SE\\attendance.txt");
				while(!fin.eof()){
					do{
					fin>>si;
					if(si==s){
						tag=1;
						getline(fin,su);
						while(su!="***"){
						 gotoxy(45,i++);
						 cout<<su<<"\n";
						 getline(fin,su);
						}
						}	
					}while(si!=s);
				}
				fin.close();
			}
		}
	fin1.close();
	fin2.close();
	getch();	
}
void Attendance::printCSattendance(){
	clear_Area(45,13,115,11);
	string s,si,su,pass,c3,c4;
	int i=13,tag=0,tag1=0;
	ifstream fin1,fin2;
	fin1.open("CSIT\\Usernames.txt");
	fin2.open("CSIT\\Passwords.txt");
	clear_Area(45,13,115,14);
	gotoxy(45,14);
	cout<<"Enter your username : ";
	cin>>s;
	gotoxy(45,15);
	cout<<"Enter you Password to verify that its you : ";
	cin>>pass;
		while(!fin1.eof() || !fin2.eof()){
			getline(fin1,c3);
			getline(fin2,c4);
			if(s==c3 && pass==c4){
				tag1=1;
				clear_Area(45,13,115,14);
				ifstream fin;
				fin.open("All Details CS\\attendance.txt");
				while(!fin.eof()){
					do{
					fin>>si;
					if(si==s){
						tag=1;
						getline(fin,su);
						while(su!="***"){
						 gotoxy(45,i++);
						 cout<<su<<"\n";
						 getline(fin,su);
						}
						}
					break;	
					}while(si!=s);
				}
				fin.close();
			}
		}
	fin1.close();
	fin2.close();
	getch();
}
void Attendance::printCSEattendance(){
	clear_Area(45,13,115,11);
	string s,si,su,pass,c3,c4;
	int i=13,tag=0,tag1=0;
	ifstream fin1,fin2;
	fin1.open("CIS\\Usernames.txt");
	fin2.open("CIS\\Passwords.txt");
	clear_Area(45,13,115,14);
	gotoxy(45,14);
	cout<<"Enter your username : ";
	cin>>s;
	gotoxy(45,15);
	cout<<"Enter you Password to verify that its you : ";
	cin>>pass;
		while(!fin1.eof() || !fin2.eof()){
			getline(fin1,c3);
			getline(fin2,c4);
			if(s==c3 && pass==c4){
				tag1=1;
				clear_Area(45,13,115,14);
				ifstream fin;
				fin.open("All Details CSE\\attendance.txt");
				while(!fin.eof()){
					do{
					fin>>si;
					if(si==s){
						tag=1;
						getline(fin,su);
						while(su!="***"){
						 gotoxy(45,i++);
						 cout<<su<<"\n";
						 getline(fin,su);
						}
						}	
					}while(si!=s);
				}
				fin.close();
			}
		}
	fin1.close();
	fin2.close();
	getch();	
}

/*********************************************************** STUDENT CLASS ***************************************************************/
class Student : public Person,public virtual Department,public virtual Attendance,public Courses{

	string roll_no,enroll,board,email;
	public:
	Student();
	void setRollNo(string);
	void setEnroll(string);
	void setBoard(string);
	void setEmail(string);
	string getRollNo()const;	
	string getEnroll()const;	
	string getBoard()const;
	string getEmail()const;
	void printGPA();
	//void functionToMakeItAbstract();
	~Student();	
};

/******************************************************* STUDENT CLASS FUNCTIONS *********************************************************/
Student::Student(){
	board = "none";
	roll_no = "none";
	enroll = "none";
	email = "none";
}
Student::~Student(){
	
}
void Student::setBoard(string board){
	this->board=board;
}
void Student::setRollNo(string roll_no){
	this->roll_no=roll_no;
}
void Student::setEnroll(string enroll){
	this->enroll=enroll;
}
void Student::setEmail(string email){
	this->email=email;
}
string Student::getBoard()const{
	return board;
}
string Student::getEnroll()const{
	return enroll;
}
string Student::getRollNo()const{
	return roll_no;
}
string Student::getEmail()const{
	return email;		
}

void Student::printGPA(){
	clear_Area(45,15,113,11);
	string name;
	ifstream fin;
	//fin.open("All Details CSE\\GPA.txt");
	gotoxy(45,15); cout << "Enter your name : ";
    getline(cin, name);
	name = "notepad \"" +name+ "\"";
	clear_Area(45,13,115,11);
	gotoxy(45,15); cout<<"Your GPA Transcript is being generated";
	Sleep(4000);
	system((name+".txt").c_str());
	//fin.close();
}

/************************************************************* ADMIN CLASS ***************************************************************/
class Admin : public Student, public virtual Department, public virtual Attendance{
		string username,password;
		
	public:
		Admin();
		void setUsername(string);
		void setPassword(char *);
		bool checkPassword(char *);
		void getPassword(char *)const;
		string getUsername()const;
		void registerStudent();
		void registerStudentME();
		void registerStudentEE();
		void registerStudentSE();
		void registerStudentCS();
		void registerStudentCSE();
		void selectDepartment();
		void setMEAttendance();
		void setEEAttendance();
		void setSEAttendance();
		void setCSttendance();
		void setCSEAttendance();
		void setMEGPA();
		void setEEGPA();
		void setSEGPA();
		void setCSGPA();
		void setCSEGPA();
		void functionToMakeItAbstract();
		~Admin();
		
};

/******************************************************** ADMIN CLASS FUNCTIONS **********************************************************/
Admin::Admin(){
	username = "none";
	password = "none";
}
Admin::~Admin(){
	
}
void Admin::setUsername(string s){
	this->username=s;
}
string Admin::getUsername()const{
	return username;
}
bool Admin::checkPassword(char *password){
	char p[5];
	int i=0,l=strlen(password);
	while(i<l)
	{
	p[i]=getch();
	cout<<"*";
	++i;
	}
	return (p==password);
}
bool Password(string s){ 
	
   	char ch, incrementer='A';
   	int i=0,j;
   	char* pass = new char[20];
   	gotoxy(60,13); cout<<"                                            ";
   	gotoxy(45,16); cout<<"                                                                   ";
   	gotoxy(45,13);
   	string str = s;
   	cout<<s;
   	char a;
	while(ch!=13){
		ch=getch();
		if (ch == 8) {
			if (i != 0) {
				cout << "\b \b";
				i--;
			}
		}
		if(ch!=13 && ch!=8){
		   pass[i] = ch;
		   putch('*');
		   i++;
		}
	}
   	pass[i] = '\0';
   	if (str == "ENTER PASSWORD: "){
   		if(strcmp(pass,password)==0){
    		gotoxy(45,16);
    		cout<<"CORRECT PASSWORD.";
    		gotoxy(45,17);
    		cout<<"Press Any Key To Continue.";
    		getch();
    		return true;
   		}
   		else{
     		gotoxy(45,16);
     		cout<<"WRONG PASSWORD. ";
     		ch = getch();
     		if (ch == 27){
     			exit_menu();
			}
     		Password(s);
   		}
	}
   	else{
   		if(strcmpi(pass,username1)==0 || strcmpi(pass,username2)==0 || strcmpi(pass,username3)==0 || strcmpi(pass,username4)==0){
   			login();
    		gotoxy(45,16);
    		cout<<"ACCESSED TO Mr. "<<pass;
    		gotoxy(45,17);
    		cout<<"Press Any Key To Continue.";
    		getch();
    		return true;
   		}
   		else{
		   login();
     		gotoxy(45,16);
     		cout<<"INVALID USERNAME. If You are not an Employee Please Press Backspace.";
     		ch = getch();
     		if (ch == 8){
     			mainmenu_student_admin();
			}
     		else if(ch == 27){
     			exit_menu();
			}
			Password(s);
		}
	}
}

void Admin::registerStudent(){
	clear_Area(45,13,115,11);
	reg:
	string n,add,b,dept,rn,ph,em;
	Admin an;
	int a,m,c,d;
	char v;
	gotoxy(45,15);
	cout<<"1. Mechanical Engineering";
	gotoxy(45,16);
	cout<<"2. Electrical Engineering";
	gotoxy(45,17);
	cout<<"3. Software Engineering";
	gotoxy(45,18);
	cout<<"4. Computer Science and Information Technology";
	gotoxy(45,19);
	cout<<"5. Computer Info System Engineering";
	gotoxy(45,20);
	cout<<"6. Go Back";
	gotoxy(45,21);
	cout<<"Enter your choice ";
	v=getch();
	switch(v){
		case '1':
		an.registerStudentME();
		break;
		case '2':
		an.registerStudentEE();
		break;
		case 3:
		an.registerStudentSE();	
		break;
		case '4':
		an.registerStudentCS();
		break;
		case '5':
		an.registerStudentCSE();
		break;
		case '6':
		mainmenu_admin_panel();
		break;
		default:
		gotoxy(45,22);
		cout<<"Invalid Entry. Try Again";
		goto reg;
}
}
void Admin::registerStudentME(){
			me:
			Admin ned;
			clear_Area(45,13,115,11);
			string n,add,b,dept,rn,ph,em;
			int a,m,c,d;
			Admin l;
			gotoxy(45,15); cout<<"*Name: ";
			gotoxy(105,15); cout<<"*Age: ";
			gotoxy(45,16); cout<<"*Address: ";
			gotoxy(45,17); cout<<"*Board: ";
			gotoxy(105,17); cout<<"*Department: ";
			gotoxy(45,18); cout<<"*Roll no: ";
			gotoxy(105,18); cout<<"*Phone: ";
			gotoxy(105,19); cout<<"*Email: ";
			gotoxy(45,19); cout<<"Date of Birth(day/month/year): ";
			gotoxy(80,19); cout<< "-";
			gotoxy(84,19); cout<< "-";
			gotoxy(52,15); getline(cin,n);
			this->setName(n);
			gotoxy(111,15); cin>>a;
			fflush(stdin);
			this->setAge(a);
			gotoxy(55,16); getline(cin,add);
			this->setAddress(add);
			gotoxy(52,17); getline(cin,b);
			this->setBoard(b);
			gotoxy(118,17); getline(cin,dept);
			this->setDepartment(dept);
			gotoxy(55,18); getline(cin,rn);
			this->setRollNo(rn);
			gotoxy(113,18); getline(cin,ph);
			this->setPhone(ph);
			gotoxy(113,19); getline(cin,em);
			this->setEmail(em);
			gotoxy(78,19);cin>>m;
			gotoxy(82,19);cin>>c;
			gotoxy(85,19);cin>>d;
			d_o_b.setDay(m);
			d_o_b.setMonth(c);
			d_o_b.setYear(d);
			clear_Area(45,13,115,9);
	
			string s,si;
			string c1,c2;
	
			bool tag;
			ofstream fout;
			ifstream fin;
		do {
			again:
			gotoxy(45,14);cout<<"Enter a Unique Username: ";
			fflush(stdin);
			getline(cin,s);
			for(int i=0;i<s.length();i++){
			if(s[i]==32){
			gotoxy(45,15);
			cout<<"Username Cannot contain a Space! Please try again without using space.";getch();
			clear_Area(45,14,115,2);
			goto again;
		}
	}
	fin.open("Mechanical Engineering\\Usernames.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	while(!fin.eof()){
		fin>>si;
		if(si==s){
			tag=false;
			break;
		}
		tag=true;
	}
	fin.close();
		if(tag==false){
			gotoxy(45,15); cout<<"Username is already Used. Please try a Different one.";
			getch();
			clear_Area(45,14,115,2);
		}
	} while (tag==false);
	
		fout.open("Mechanical Engineering\\Usernames.txt", std::fstream::in | std::fstream::out | std::fstream::app);
		fout<<s<<"\n";
	fout.close();
	do{
		gotoxy(45,15);cout<<"Enter your new Password: ";
		cin>>c1;
		if(c1.length()>15 || c1.length()<4){
			gotoxy(45,16);cout<<"Password's length should be in between 4 to 15 characters. ";getch();
			clear_Area(45,15,115,2);
		}	
	}
	while(c1.length()>15 || c1.length()<4);
	do{
		gotoxy(45,16);cout<<"Enter your Password again: ";
		cin>>c2;
		if(c1!=c2){
			gotoxy(45,17); cout<<"You Put wrong Password"; getch();
			clear_Area(45,16,115,2);
		}	
	}
	while(c1!=c2);
	
	fout.open("Mechanical Engineering\\Passwords.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<c1<<"\n";
	fout.close();
	fout.open("All Details ME\\all details.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<s<<"\n";
	fout<<"\n"<<getName()<<"\'Details\n\n\nAge: "<<getAge()<<"\nAddress: "<<getAddress()<<"\nBoard: "<<getBoard()<<"\nDepartment: "<<getDepartment()
	<<"\nRoll No: "<<getRollNo() <<"\nEmail : "<<getEmail()<< "\nContact: "<<getPhone()<<"\n\n***\n\n";	
	ofstream fm( ("Members Details\\"+getName()+".txt").c_str() );
	fm<<"\n"<<getName()<<"\'Details\n\n\nAge: "<<getAge()<<"\nAddress: "<<"\nDate of Birth : "<<d_o_b<<getAddress()<<"\nBoard: "<<getBoard()<<"\nDepartment: "<<getDepartment()
	<<"\nRoll No: "<<getRollNo()<<"\nEmail : "<<getEmail()<< "\nContact: "<<getPhone()<<"\n\n***\n\n";	
	fout.close();
	fm.close();
	clear_Area(45,11,113,15);
	
	clear_Area(45,13,115,9);
	clear_Area(45,13,115,10);
	clear_Area(45,13,115,11);
	gotoxy(45,15);
	cout<<"Press any key to return"; getch();
	ned.setMEGPA();
}
void Admin::registerStudentEE(){
	clear_Area(45,13,115,11);
			string n,add,b,dept,rn,ph,em;
			int a,m,c,d;
			Admin l;
			gotoxy(45,15); cout<<"*Name: ";
			gotoxy(105,15); cout<<"*Age: ";
			gotoxy(45,16); cout<<"*Address: ";
			gotoxy(45,17); cout<<"*Board: ";
			gotoxy(105,17); cout<<"*Department: ";
			gotoxy(45,18); cout<<"*Roll no: ";
			gotoxy(105,18); cout<<"*Phone: ";
			gotoxy(105,19); cout<<"*Email: ";
			gotoxy(45,19); cout<<"Date of Birth(day/month/year): ";
			gotoxy(80,19); cout<< "-";
			gotoxy(84,19); cout<< "-";
			gotoxy(52,15); getline(cin,n);
			this->setName(n);
			gotoxy(111,15); cin>>a;
			fflush(stdin);
			this->setAge(a);
			gotoxy(55,16); getline(cin,add);
			this->setAddress(add);
			gotoxy(52,17); getline(cin,b);
			this->setBoard(b);
			gotoxy(118,17); getline(cin,dept);
			this->setDepartment(dept);
			gotoxy(55,18); getline(cin,rn);
			this->setRollNo(rn);
			gotoxy(113,18); getline(cin,ph);
			this->setPhone(ph);
			gotoxy(113,19); getline(cin,em);
			this->setEmail(em);
			gotoxy(78,19);cin>>m;
			gotoxy(82,19);cin>>c;
			gotoxy(85,19);cin>>d;
			d_o_b.setDay(m);
			d_o_b.setMonth(c);
			d_o_b.setYear(d);
			clear_Area(45,13,115,9);
	
			string s,si;
			string c1,c2;
	
			bool tag;
			ofstream fout;
			ifstream fin;
		do {
			again:
			gotoxy(45,14);cout<<"Enter a Unique Username: ";
			fflush(stdin);
			getline(cin,s);
			for(int i=0;i<s.length();i++){
			if(s[i]==32){
			gotoxy(45,15);
			cout<<"Username Cannot contain a Space! Please try again without using space.";getch();
			clear_Area(45,14,115,2);
			goto again;
		}
	}
	fin.open("Electrical Engineering\\Usernames.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	while(!fin.eof()){
		fin>>si;
		if(si==s){
			tag=false;
			break;
		}
		tag=true;
	}
	fin.close();
		if(tag==false){
			gotoxy(45,15); cout<<"Username is already Used. Please try a Different one.";
			getch();
			clear_Area(45,14,115,2);
		}
	} while (tag==false);
	
		fout.open("Electrical Engineering\\Usernames.txt", std::fstream::in | std::fstream::out | std::fstream::app);
		fout<<s<<"\n";
	fout.close();
	do{
		gotoxy(45,15);cout<<"Enter your new Password: ";
		cin>>c1;
		if(c1.length()>15 || c1.length()<4){
			gotoxy(45,16);cout<<"Password's length should be in between 4 to 15 characters. ";getch();
			clear_Area(45,15,115,2);
		}	
	}
	while(c1.length()>15 || c1.length()<4);
	do{
		gotoxy(45,16);cout<<"Enter your Password again: ";
		cin>>c2;
		if(c1!=c2){
			gotoxy(45,17); cout<<"You Put wrong Password"; getch();
			clear_Area(45,16,115,2);
		}	
	}
	while(c1!=c2);
	
	fout.open("Electrical Engineering\\Passwords.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<c1<<"\n";
	fout.close();
	fout.open("All Details EE\\all details.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<s<<"\n";
	fout<<"\n"<<getName()<<"\'Details\n\n\nAge: "<<getAge()<<"\nAddress: "<<getAddress()<<"\nBoard: "<<getBoard()<<"\nDepartment: "<<getDepartment()
	<<"\nRoll No: "<<getRollNo() <<"\nEmail : "<<getEmail()<< "\nContact: "<<getPhone()<<"\n\n***\n\n";	
	ofstream fm( ("Members Details\\"+getName()+".txt").c_str() );
	fm<<"\n"<<getName()<<"\'Details\n\n\nAge: "<<getAge()<<"\nAddress: "<<"\nDate of Birth : "<<d_o_b<<getAddress()<<"\nBoard: "<<getBoard()<<"\nDepartment: "<<getDepartment()
	<<"\nRoll No: "<<getRollNo()<<"\nEmail : "<<getEmail()<< "\nContact: "<<getPhone()<<"\n\n***\n\n";	
	fout.close();
	fm.close();
	clear_Area(45,13,115,9);
	clear_Area(45,13,115,10);
	clear_Area(45,13,115,11);
	gotoxy(45,15);
	cout<<"Press any key to return"; getch();
	l.setEEGPA();
}
void Admin::registerStudentSE(){
	clear_Area(45,13,115,11);
			Admin ned;
			string n,add,b,dept,rn,ph,em;
			int a,m,c,d;
			Admin l;
			gotoxy(45,15); cout<<"*Name: ";
			gotoxy(105,15); cout<<"*Age: ";
			gotoxy(45,16); cout<<"*Address: ";
			gotoxy(45,17); cout<<"*Board: ";
			gotoxy(105,17); cout<<"*Department: ";
			gotoxy(45,18); cout<<"*Roll no: ";
			gotoxy(105,18); cout<<"*Phone: ";
			gotoxy(105,19); cout<<"*Email: ";
			gotoxy(45,19); cout<<"Date of Birth(day/month/year): ";
			gotoxy(80,19); cout<< "-";
			gotoxy(84,19); cout<< "-";
			gotoxy(52,15); getline(cin,n);
			this->setName(n);
			gotoxy(111,15); cin>>a;
			fflush(stdin);
			this->setAge(a);
			gotoxy(55,16); getline(cin,add);
			this->setAddress(add);
			gotoxy(52,17); getline(cin,b);
			this->setBoard(b);
			gotoxy(118,17); getline(cin,dept);
			this->setDepartment(dept);
			gotoxy(55,18); getline(cin,rn);
			this->setRollNo(rn);
			gotoxy(113,18); getline(cin,ph);
			this->setPhone(ph);
			gotoxy(113,19); getline(cin,em);
			this->setEmail(em);
			gotoxy(78,19);cin>>m;
			gotoxy(82,19);cin>>c;
			gotoxy(85,19);cin>>d;
			d_o_b.setDay(m);
			d_o_b.setMonth(c);
			d_o_b.setYear(d);
			clear_Area(45,13,115,9);
	
			string s,si;
			string c1,c2;
	
			bool tag;
			ofstream fout;
			ifstream fin;
		do {
			again:
			gotoxy(45,14);cout<<"Enter a Unique Username: ";
			fflush(stdin);
			getline(cin,s);
			for(int i=0;i<s.length();i++){
			if(s[i]==32){
			gotoxy(45,15);
			cout<<"Username Cannot contain a Space! Please try again without using space.";getch();
			clear_Area(45,14,115,2);
			goto again;
		}
	}
	fin.open("Software Engineering\\Usernames.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	while(!fin.eof()){
		fin>>si;
		if(si==s){
			tag=false;
			break;
		}
		tag=true;
	}
	fin.close();
		if(tag==false){
			gotoxy(45,15); cout<<"Username is already Used. Please try a Different one.";
			getch();
			clear_Area(45,14,115,2);
		}
	} while (tag==false);
	
		fout.open("Software Engineering\\Usernames.txt", std::fstream::in | std::fstream::out | std::fstream::app);
		fout<<s<<"\n";
	fout.close();
	do{
		gotoxy(45,15);cout<<"Enter your new Password: ";
		cin>>c1;
		if(c1.length()>15 || c1.length()<4){
			gotoxy(45,16);cout<<"Password's length should be in between 4 to 15 characters. ";getch();
			clear_Area(45,15,115,2);
		}	
	}
	while(c1.length()>15 || c1.length()<4);
	do{
		gotoxy(45,16);cout<<"Enter your Password again: ";
		cin>>c2;
		if(c1!=c2){
			gotoxy(45,17); cout<<"You Put wrong Password"; getch();
			clear_Area(45,16,115,2);
		}	
	}
	while(c1!=c2);
	
	fout.open("Software Engineering\\Passwords.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<c1<<"\n";
	fout.close();
	fout.open("All Details SE\\all details.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<s<<"\n";
	fout<<"\n"<<getName()<<"\'Details\n\n\nAge: "<<getAge()<<"\nAddress: "<<getAddress()<<"\nBoard: "<<getBoard()<<"\nDepartment: "<<getDepartment()
	<<"\nRoll No: "<<getRollNo() <<"\nEmail : "<<getEmail()<< "\nContact: "<<getPhone()<<"\n\n***\n\n";	
	ofstream fm( ("Members Details\\"+getName()+".txt").c_str() );
	fm<<"\n"<<getName()<<"\'Details\n\n\nAge: "<<getAge()<<"\nAddress: "<<"\nDate of Birth : "<<d_o_b<<getAddress()<<"\nBoard: "<<getBoard()<<"\nDepartment: "<<getDepartment()
	<<"\nRoll No: "<<getRollNo()<<"\nEmail : "<<getEmail()<< "\nContact: "<<getPhone()<<"\n\n***\n\n";	
	fout.close();
	fm.close();
	clear_Area(45,13,115,9);
	clear_Area(45,13,115,10);
	clear_Area(45,13,115,11);
	gotoxy(45,15);
	cout<<"Press any key to return"; getch();
	//l.setSEGPA();
}
void Admin::registerStudentCS(){
	clear_Area(45,13,115,11);
			string n,add,b,dept,rn,ph,em;
			int a,m,c,d;
			Admin l;
			gotoxy(45,15); cout<<"*Name: ";
			gotoxy(105,15); cout<<"*Age: ";
			gotoxy(45,16); cout<<"*Address: ";
			gotoxy(45,17); cout<<"*Board: ";
			gotoxy(105,17); cout<<"*Department: ";
			gotoxy(45,18); cout<<"*Roll no: ";
			gotoxy(105,18); cout<<"*Phone: ";
			gotoxy(105,19); cout<<"*Email: ";
			gotoxy(45,19); cout<<"Date of Birth(day/month/year): ";
			gotoxy(80,19); cout<< "-";
			gotoxy(84,19); cout<< "-";
			gotoxy(52,15); getline(cin,n);
			this->setName(n);
			gotoxy(111,15); cin>>a;
			fflush(stdin);
			this->setAge(a);
			gotoxy(55,16); getline(cin,add);
			this->setAddress(add);
			gotoxy(52,17); getline(cin,b);
			this->setBoard(b);
			gotoxy(118,17); getline(cin,dept);
			this->setDepartment(dept);
			gotoxy(55,18); getline(cin,rn);
			this->setRollNo(rn);
			gotoxy(113,18); getline(cin,ph);
			this->setPhone(ph);
			gotoxy(113,19); getline(cin,em);
			this->setEmail(em);
			gotoxy(78,19);cin>>m;
			gotoxy(82,19);cin>>c;
			gotoxy(85,19);cin>>d;
			d_o_b.setDay(m);
			d_o_b.setMonth(c);
			d_o_b.setYear(d);
			clear_Area(45,13,115,9);
	
			string s,si;
			string c1,c2;
	
			bool tag;
			ofstream fout;
			ifstream fin;
		do {
			again:
			gotoxy(45,14);cout<<"Enter a Unique Username: ";
			fflush(stdin);
			getline(cin,s);
			for(int i=0;i<s.length();i++){
			if(s[i]==32){
			gotoxy(45,15);
			cout<<"Username Cannot contain a Space! Please try again without using space.";getch();
			clear_Area(45,14,115,2);
			goto again;
		}
	}
	fin.open("CSIT\\Usernames.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	while(!fin.eof()){
		fin>>si;
		if(si==s){
			tag=false;
			break;
		}
		tag=true;
	}
	fin.close();
		if(tag==false){
			gotoxy(45,15); cout<<"Username is already Used. Please try a Different one.";
			getch();
			clear_Area(45,14,115,2);
		}
	} while (tag==false);
	
		fout.open("CSIT\\Usernames.txt", std::fstream::in | std::fstream::out | std::fstream::app);
		fout<<s<<"\n";
	fout.close();
	do{
		gotoxy(45,15);cout<<"Enter your new Password: ";
		cin>>c1;
		if(c1.length()>15 || c1.length()<4){
			gotoxy(45,16);cout<<"Password's length should be in between 4 to 15 characters. ";getch();
			clear_Area(45,15,115,2);
		}	
	}
	while(c1.length()>15 || c1.length()<4);
	do{
		gotoxy(45,16);cout<<"Enter your Password again: ";
		cin>>c2;
		if(c1!=c2){
			gotoxy(45,17); cout<<"You Put wrong Password"; getch();
			clear_Area(45,16,115,2);
		}	
	}
	while(c1!=c2);
	
	fout.open("CSIT\\Passwords.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<c1<<"\n";
	fout.close();
	fout.open("All Details CS\\all details.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<s<<"\n";
	fout<<"\n"<<getName()<<"\'Details\n\n\nAge: "<<getAge()<<"\nAddress: "<<getAddress()<<"\nBoard: "<<getBoard()<<"\nDepartment: "<<getDepartment()
	<<"\nRoll No: "<<getRollNo() <<"\nEmail : "<<getEmail()<< "\nContact: "<<getPhone()<<"\n\n***\n\n";	
	ofstream fm( ("Members Details\\"+getName()+".txt").c_str() );
	fm<<"\n"<<getName()<<"\'Details\n\n\nAge: "<<getAge()<<"\nAddress: "<<"\nDate of Birth : "<<d_o_b<<getAddress()<<"\nBoard: "<<getBoard()<<"\nDepartment: "<<getDepartment()
	<<"\nRoll No: "<<getRollNo()<<"\nEmail : "<<getEmail()<< "\nContact: "<<getPhone()<<"\n\n***\n\n";	
	fout.close();
	fm.close();
	//clear_Area(45,13,115,9);
	//clear_Area(45,13,115,10);
	clear_Area(45,13,115,11);
	gotoxy(45,15);
	cout<<"Press any key to proceed"; getch();
	l.setCSGPA();
}
void Admin::registerStudentCSE(){
	clear_Area(45,13,115,11);
			string n,add,b,dept,rn,ph,em;
			int a,m,c,d;
			Admin l;
			gotoxy(45,15); cout<<"*Name: ";
			gotoxy(105,15); cout<<"*Age: ";
			gotoxy(45,16); cout<<"*Address: ";
			gotoxy(45,17); cout<<"*Board: ";
			gotoxy(105,17); cout<<"*Department: ";
			gotoxy(45,18); cout<<"*Roll no: ";
			gotoxy(105,18); cout<<"*Phone: ";
			gotoxy(105,19); cout<<"*Email: ";
			gotoxy(45,19); cout<<"Date of Birth(day/month/year): ";
			gotoxy(80,19); cout<< "-";
			gotoxy(84,19); cout<< "-";
			gotoxy(52,15); getline(cin,n);
			this->setName(n);
			gotoxy(111,15); cin>>a;
			fflush(stdin);
			this->setAge(a);
			gotoxy(55,16); getline(cin,add);
			this->setAddress(add);
			gotoxy(52,17); getline(cin,b);
			this->setBoard(b);
			gotoxy(118,17); getline(cin,dept);
			this->setDepartment(dept);
			gotoxy(55,18); getline(cin,rn);
			this->setRollNo(rn);
			gotoxy(113,18); getline(cin,ph);
			this->setPhone(ph);
			gotoxy(113,19); getline(cin,em);
			this->setEmail(em);
			gotoxy(78,19);cin>>m;
			gotoxy(82,19);cin>>c;
			gotoxy(85,19);cin>>d;
			d_o_b.setDay(m);
			d_o_b.setMonth(c);
			d_o_b.setYear(d);
			clear_Area(45,13,115,9);
	
			string s,si;
			string c1,c2;
	
			bool tag;
			ofstream fout;
			ifstream fin;
		do {
			again:
			gotoxy(45,14);cout<<"Enter a Unique Username: ";
			fflush(stdin);
			getline(cin,s);
			for(int i=0;i<s.length();i++){
			if(s[i]==32){
			gotoxy(45,15);
			cout<<"Username Cannot contain a Space! Please try again without using space.";getch();
			clear_Area(45,14,115,2);
			goto again;
		}
	}
	fin.open("CIS\\Usernames.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	while(!fin.eof()){
		fin>>si;
		if(si==s){
			tag=false;
			break;
		}
		tag=true;
	}
	fin.close();
		if(tag==false){
			gotoxy(45,15); cout<<"Username is already Used. Please try a Different one.";
			getch();
			clear_Area(45,14,115,2);
		}
	} while (tag==false);
	
		fout.open("CIS\\Usernames.txt", std::fstream::in | std::fstream::out | std::fstream::app);
		fout<<s<<"\n";
	fout.close();
	do{
		gotoxy(45,15);cout<<"Enter your new Password: ";
		cin>>c1;
		if(c1.length()>15 || c1.length()<4){
			gotoxy(45,16);cout<<"Password's length should be in between 4 to 15 characters. ";getch();
			clear_Area(45,15,115,2);
		}	
	}
	while(c1.length()>15 || c1.length()<4);
	do{
		gotoxy(45,16);cout<<"Enter your Password again: ";
		cin>>c2;
		if(c1!=c2){
			gotoxy(45,17); cout<<"You Put wrong Password"; getch();
			clear_Area(45,16,115,2);
		}	
	}
	while(c1!=c2);
	
	fout.open("CIS\\Passwords.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<c1<<"\n";
	fout.close();
	fout.open("All Details CSE\\all details.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<s<<"\n";
	fout<<"\n"<<getName()<<"\'Details\n\n\nAge: "<<getAge()<<"\nAddress: "<<getAddress()<<"\nBoard: "<<getBoard()<<"\nDepartment: "<<getDepartment()
	<<"\nRoll No: "<<getRollNo() <<"\nEmail : "<<getEmail()<< "\nContact: "<<getPhone()<<"\n\n***\n\n";	
	ofstream fm( ("Members Details\\"+getName()+".txt").c_str() );
	fm<<"\n"<<getName()<<"\'Details\n\n\nAge: "<<getAge()<<"\nAddress: "<<"\nDate of Birth : "<<d_o_b<<getAddress()<<"\nBoard: "<<getBoard()<<"\nDepartment: "<<getDepartment()
	<<"\nRoll No: "<<getRollNo()<<"\nEmail : "<<getEmail()<< "\nContact: "<<getPhone()<<"\n\n***\n\n";	
	fout.close();
	fm.close();
	clear_Area(45,13,115,9);
	clear_Area(45,13,115,10);
	clear_Area(45,13,115,11);
	gotoxy(45,15);
	cout<<"Press any key to return"; getch();
	l.setCSEGPA();
}
void Admin::selectDepartment(){
	de:
	char c;
	clear_Area(45,13,115,11);
	Department dept;
	gotoxy(45,15);
	cout<<"1. Mechanical Engineering";
	gotoxy(45,16);
	cout<<"2. Electrical Engineering";
	gotoxy(45,17);
	cout<<"3. Software Engineering";
	gotoxy(45,18);
	cout<<"4. Computer Science and Information Technology";
	gotoxy(45,19);
	cout<<"5. Computer and Info System Engineering";
	gotoxy(45,20);
	cout<<"Enter choice";
	c=getch();
	switch(c){
		case '1':
			select:
			clear_Area(45,11,113,15);
			char m;
			gotoxy(45,15);
			cout<<"1. Display Username and Passwords";
			gotoxy(45,16);
			cout<<"2. Search by Username";
			gotoxy(45,17);
			cout<<"Choose one";
			m=getch();
			switch(m){
				case '1':
					dept.showAllDetailsME();
					break;
				case '2':
					dept.showDetailsME();
					break;
				default:
					gotoxy(45,19);
					cout<<"Invalid entry";
					goto select; 			
			}
			//an.showDetailsME();
			//break;
		case '2':
			clear_Area(45,11,113,15);
			selectEE:
			char e;
			gotoxy(45,15);
			cout<<"1. Display Username and Passwords";
			gotoxy(45,16);
			cout<<"2. Search by Username";
			gotoxy(45,17);
			cout<<"Choose one";
			e=getch();
			switch(e){
				case '1':
					dept.showAllDetailsEE();
					break;
				case '2':
					dept.showDetailsEE();
					break;
				default:
					gotoxy(45,19);
					cout<<"Invalid Entry";
					goto selectEE;
			}
			//an.showDetailsEE();
			//break;
		case '3':
			clear_Area(45,11,113,15);
			selectSE:
			char s;
			gotoxy(45,15);
			cout<<"1. Display Username and Passwords";
			gotoxy(45,16);
			cout<<"2. Search by Username";
			gotoxy(45,17);
			cout<<"Choose one";
			s=getch();
			switch(s){
				case '1':
					dept.showAllDetailsSE();
					break;
				case '2':
					dept.showDetailsSE();
					break;
				default:
					gotoxy(45,19);
					cout<<"Invalid Entry";
					goto selectSE;
			}
			//an.showDetailsSE();
			//	break;
		case '4':
			clear_Area(45,11,113,15);
			selectCS:
			char cs;
			gotoxy(45,15);
			cout<<"1. Display Username and Passwords";
			gotoxy(45,16);
			cout<<"2. Search by Username";
			gotoxy(45,17);
			cout<<"Choose one";
			cs=getch();
			switch(cs){
				case '1':
					dept.showAllDetailsCS();
					break;
				case '2':
					dept.showDetailsCS();
					break;
				default:
					gotoxy(45,19);
					cout<<"Invalid Entry";
					goto selectCS;
			}
			//an.showDetailsCS();
			//break;
		case '5':
			clear_Area(45,11,113,15);
			selectCSE:
			char cse;
			gotoxy(45,15);
			cout<<"1. Display Username and Passwords";
			gotoxy(45,16);
			cout<<"2. Search by Username";
			gotoxy(45,17);
			cout<<"Choose one";
			cse=getch();
			switch(cse){
				case '1':
					dept.showAllDetailsCSE();
					break; 
				case '2':
					dept.showDetailsCSE();
					break;
				default:
					gotoxy(45,19);
					cout<<"Invalid Entry.";
					goto selectCSE;
			}
			//an.showDetailsCSE();
			//break;
		default:
			gotoxy(45,22);
			cout<<"Invalid Entry. Try Again";
			goto de;
	}
}
void Admin::setMEAttendance(){
	clear_Area(45,11,113,15);
	attme:
	string ap,fe,bee,wp,st,th,n,rn,s;
	ofstream fout;
	ifstream fin;
	gotoxy(45,13); cout<<"Name:";
	gotoxy(70,13); cout<<"Roll Number:";
	gotoxy(90,13); cout<<"Username:";
	gotoxy(45,16); cout<<"Applied Physics:";
	gotoxy(45,17); cout<<"Functional English:";
	gotoxy(45,18); cout<<"Basic Electricity and Electronics:";
	gotoxy(45,19); cout<<"Workshop Practice:";
	gotoxy(45,20); cout<<"Statics:";
	gotoxy(45,21); cout<<"Thermodynamics:";
	fflush(stdin);
	gotoxy(50,13); getline(cin,n);
	this->setName(n);
	gotoxy(82,13); getline(cin,rn);
	this->setRollNo(rn);
	gotoxy(100,13); cin>>s;
	fflush(stdin);
	gotoxy(61,16); getline(cin,ap);
	this->setC1(ap);
	gotoxy(64,17); getline(cin,fe);
	this->setC2(fe);
	gotoxy(81,18); getline(cin,bee);
	this->setC3(bee);
	gotoxy(63,19); getline(cin,wp);
	this->setC4(wp);
	gotoxy(54,20); getline(cin,st);
	this->setC5(st);
	gotoxy(62,21); getline(cin,th);
	this->setC6(th);
	string e;
	fout.open("All Details ME\\attendance.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<e<<"\n";
	fout<<s<<"\n";	
	fout<<"\n"<<getName()<<" ATTENDANCE RECORD"<<"\nRoll Number: "<<getRollNo()<<"\n\n"<<"Applied Physics: "<<getC1()<<"\nFunctional English: "<<getC2()<<"\nBasic Electricity and Electronics: "<<getC3()
	<<"\nWorkshop Practice: "<<getC4()<<"\nStatics: "<<getC5()<<"\nThermodynamics: "<<getC6()<<"\n\n***\n\n";
	ofstream fm( ("All Details ME\\"+getName()+".txt").c_str() );
	fm<<"\n"<<getName()<<" ATTENDANCE RECORD"<<"\n\n"<<"Applied Physics: "<<getC1()<<"\nFunctional English: "<<getC2()<<"\nBasic Electricity and Electronics: "<<getC3()
	<<"\nWorkshop Practice: "<<getC4()<<"\nStatics: "<<getC5()<<"\nThermodynamics: "<<getC6()<<"\n\n***\n\n";
	fout.close();
	fm.close();
	clear_Area(45,11,113,15);
	gotoxy(45,15);
	cout<<"Press any key to return"; getch();
	mainmenu_admin_panel();
}
void Admin::setEEAttendance(){
	gotoxy(45,16); cout<<"Press any key to proceed for attendance";
	clear_Area(45,11,113,15);
	attee:
	string ed,ca,de,es,cp,ps,n,rn,s;
	ofstream fout;
	ifstream fin;
	gotoxy(45,13); cout<<"Name:";
	gotoxy(70,13); cout<<"Roll Number:";
	gotoxy(90,13); cout<<"Username:";
	gotoxy(45,16); cout<<"Engineering Drawing:";
	gotoxy(45,17); cout<<"Circuit Analysis:";
	gotoxy(45,18); cout<<"Differential Equations:";
	gotoxy(45,19); cout<<"Engineering Surveying:";
	gotoxy(45,20); cout<<"Computers and Programming:";
	gotoxy(45,21); cout<<"Pakistan Studies:";
	fflush(stdin);
	gotoxy(50,13); getline(cin,n);
	this->setName(n);
	gotoxy(82,13); getline(cin,rn);
	this->setRollNo(rn);
	gotoxy(100,13); cin>>s;
	fflush(stdin);
	gotoxy(66,16); getline(cin,ed);
	this->setC1(ed);
	gotoxy(62,17); getline(cin,ca);
	this->setC2(ca);
	gotoxy(68,18); getline(cin,de);
	this->setC3(de);
	gotoxy(67,19); getline(cin,es);
	this->setC4(es);
	gotoxy(71,20); getline(cin,cp);
	this->setC5(cp);
	gotoxy(62,21); getline(cin,ps);
	this->setC6(ps);
	string e;
	fout.open("All Details EE\\attendance.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<e<<"\n";	
	fout<<s<<"\n";
	fout<<"\n"<<getName()<<" ATTENDANCE RECORD"<<"\n\n"<<"Engineering Drawing: "<<getC1()<<"\nCircuit Analysis: "<<getC2()<<"\nDifferential Equations: "<<getC3()
	<<"\nEngineering Surveying: "<<getC4()<<"\nComputers and Programming: "<<getC5()<<"\nPakistan Studies: "<<getC6()<<"\n\n***\n\n";
	ofstream fm( ("All Details EE\\"+getName()+".txt").c_str() );
	fm<<"\n"<<getName()<<" ATTENDANCE RECORD"<<"\n\n"<<"Engineering Drawing: "<<getC1()<<"\nCircuit Analysis: "<<getC2()<<"\nDifferential Equations: "<<getC3()
	<<"\nEngineering Surveying: "<<getC4()<<"\nComputers and Programming: "<<getC5()<<"\nPakistan Studies: "<<getC6()<<"\n\n***\n\n";
	fout.close();
	fm.close();
	clear_Area(45,11,113,15);
	gotoxy(45,15);
	cout<<"Press any key to return"; getch();
	mainmenu_admin_panel();
}
void Admin::setSEAttendance(){
	clear_Area(45,11,113,15);
	attse:
	string daa,oop,ap,be,is,s,n,rn;
	ofstream fout;
	ifstream fin;
	gotoxy(45,13); cout<<"Name:";
	gotoxy(70,13); cout<<"Roll Number:";
	gotoxy(90,13); cout<<"Username:";
	gotoxy(45,16); cout<<"Data Structures Algorithm and Application:";
	gotoxy(45,17); cout<<"Object Oriented Programming:";
	gotoxy(45,18); cout<<"Applied Physics:";
	gotoxy(45,19); cout<<"Basic Electronics:";
	gotoxy(45,20); cout<<"Islamic Studies:";
	fflush(stdin);
	gotoxy(50,13); getline(cin,n);
	this->setName(n);
	gotoxy(82,13); getline(cin,rn);
	this->setRollNo(rn);
	gotoxy(100,13); cin>>s;
	fflush(stdin);
	gotoxy(87,16); getline(cin,daa);
	this->setC1(daa);
	gotoxy(73,17); getline(cin,oop);
	this->setC2(oop);
	gotoxy(52,18); getline(cin,ap);
	this->setC3(ap);
	gotoxy(52,18); getline(cin,be);
	this->setC4(be);
	gotoxy(53,19); getline(cin,is);
	this->setC5(is);
	string e;
	fout.open("All Details SE\\attendance.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<e<<"\n";	
	fout<<"\n"<<getName()<<" ATTENDANCE RECORD"<<"\nRoll Number: "<<getRollNo()<<"\n\n"<<"Data Structures Algorithm and Application: "<<getC1()<<"\nObject Oriented Programming: "<<getC2()<<"\nApplied Physics: "<<getC3()
	<<"\nBasic Electronics: "<<getC4()<<"\nIslamic Studies: "<<getC5()<<"\n\n***\n\n";
	ofstream fm( ("All Details SE\\"+getName()+".txt").c_str() );
	fm<<"\n"<<getName()<<" ATTENDANCE RECORD"<<"\n\n"<<"Engineering Drawing: "<<getC1()<<"\nCircuit Analysis: "<<getC2()<<"\nDifferential Equations: "<<getC3()
	<<"\nEngineering Surveying: "<<getC4()<<"\nComputers and Programming: "<<getC5()<<"\nPakistan Studies: "<<getC6()<<"\n\n***\n\n";
	fout.close();
	fm.close();
	clear_Area(45,11,113,15);
	gotoxy(45,15);
	cout<<"Press any key to return"; getch();
	mainmenu_admin_panel();
}
void Admin::setCSttendance(){
	//clear_Area(45,11,113,15);
	attcs:
	char ch;
	string daa,oop,ds,fe,ps,s,n,rn;
	ofstream fout;
	ifstream fin;
	gotoxy(45,13); cout<<"Name:";
	gotoxy(70,13); cout<<"Roll Number:";
	gotoxy(90,13); cout<<"Username:";
	gotoxy(45,14); printLineSlowly('|', 49, 5);
	gotoxy(94,14); printStringSlowly(" STUDENT'S ATTENDANCE ", 5);
	gotoxy(115,14); printLineSlowly('|', 49, 5);
	gotoxy(45,16); cout<<"Data Structures Algorithm and Application:";
	gotoxy(45,17); cout<<"Object Oriented Programming:";
	gotoxy(45,18); cout<<"Discrete Structures:";
	gotoxy(45,19); cout<<"Functional English:";
	gotoxy(45,20); cout<<"Pakistan Studies:";
	fflush(stdin);
	gotoxy(50,13); getline(cin,n);
	this->setName(n);
	gotoxy(82,13); getline(cin,rn);
	this->setRollNo(rn);
	gotoxy(100,13); cin>>s;
	fflush(stdin);
	gotoxy(87,16); getline(cin,daa);
	this->setC1(daa);
	gotoxy(73,17); getline(cin,oop);
	this->setC2(oop);
	gotoxy(66,18); getline(cin,ds);
	this->setC3(ds);
	gotoxy(64,19); getline(cin,fe);
	this->setC4(fe);
	gotoxy(62,20); getline(cin,ps);
	this->setC5(ps);
	string e;
	fout.open("All Details CS\\attendance.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<e<<"\n";
	fout<<s<<"\n";	
	fout<<"\n"<<getName()<<" ATTENDANCE RECORD"<<"\nRoll Number: "<<getRollNo()<<"\n\n"<<"Data Structures Algorithm and Application: "<<getC1()<<"\nObject Oriented Programming: "<<getC2()<<"\nDiscrete Structures: "<<getC3()
	<<"\nFunctional English: "<<getC4()<<"\nPakistan Studies: "<<getC5()<<"\n\n***\n\n";
	ofstream fm( ("All Details CS\\"+getName()+" attendance.txt").c_str() );
	fm<<"\n"<<getName()<<" ATTENDANCE RECORD"<<"\n\n"<<"Data Structures Algorithm and Application: "<<getC1()<<"\nObject Oriented Programming: "<<getC2()<<"\nDiscrete Structures: "<<getC3()
	<<"\nFunctional English: "<<getC4()<<"\nPakistan Studies: "<<getC5()<<"\n\n***\n\n";
	fout.close();
	fm.close();
	clear_Area(45,11,113,15);
	gotoxy(45,15);
	cout<<"Press any key to return"; ch=getch();
	mainmenu_admin_panel();
}
void Admin::setCSEAttendance(){
	clear_Area(45,11,113,15);
	attcse:
	string oop,ds,bme,be,ap,s,n,rn;
	ofstream fout;
	ifstream fin;
	gotoxy(45,13); cout<<"Name:";
	gotoxy(70,13); cout<<"Roll Number:";
	gotoxy(90,13); cout<<"Username:";
	gotoxy(45,16); cout<<"Object Oriented Programming:";
	gotoxy(45,17); cout<<"Discrete Structures:";
	gotoxy(45,18); cout<<"Basic Mechanical Engineering:";
	gotoxy(45,19); cout<<"Basic Electronics:";
	gotoxy(45,20); cout<<"Applied Physics:";
	fflush(stdin);
	gotoxy(50,13); getline(cin,n);
	this->setName(n);
	gotoxy(82,13); getline(cin,rn);
	this->setRollNo(rn);
	gotoxy(100,13); cin>>s;
	fflush(stdin);
	gotoxy(73,16); getline(cin,oop);
	this->setC1(oop);
	gotoxy(66,17); getline(cin,ds);
	this->setC2(ds);
	gotoxy(75,18); getline(cin,bme);
	this->setC3(bme);
	gotoxy(64,19); getline(cin,be);
	this->setC4(be);
	gotoxy(61,20); getline(cin,ap);
	this->setC5(ap);
	string e;
	fout.open("All Details CS\\attendance.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<e<<"\n";
	fout<<s<<"\n";	
	fout<<"\n"<<getName()<<" ATTENDANCE RECORD"<<"\nRoll Number: "<<getRollNo()<<"\n\n"<<"Object Oriented Programming: "<<getC1()<<"\nDiscrete Structures: "<<getC2()<<"\nBasic Mechanical Engineering: "<<getC3()
	<<"\nBasic Electronics: "<<getC4()<<"\nApplied Physics: "<<getC5()<<"\n\n***\n\n";
	ofstream fm( ("All Details CS\\"+getName()+" attendance.txt").c_str() );
	fm<<"\n"<<getName()<<" ATTENDANCE RECORD"<<"\n\n"<<"Object Oriented Programming: "<<getC1()<<"\nDiscrete Structures: "<<getC2()<<"\nBasic Mechanical Engineering: "<<getC3()
	<<"\nBasic Electronics: "<<getC4()<<"\nApplied Physics: "<<getC5()<<"\n\n***\n\n";
	fout.close();
	fm.close();
	clear_Area(45,11,113,15);
	gotoxy(45,15);
	cout<<"Press any key to return"; getch();
	mainmenu_admin_panel();
}
void Admin::setMEGPA(){
	clear_Area(45,11,113,15);
	gpame:
	Admin ned;
	string ac,c,es,ps,ed,s,n,rn;
	ofstream fout;
	ifstream fin;
	gotoxy(45,13); cout<<"Name:";
	gotoxy(70,13); cout<<"Roll Number:";
	gotoxy(90,13); cout<<"Username:";
	gotoxy(95,14); cout<<"GPA SECTION";
	gotoxy(45,16); cout<<"Applied Chemistry:";
	gotoxy(45,17); cout<<"Calculus:";
	gotoxy(45,18); cout<<"Engineering Survey-I:";
	gotoxy(45,19); cout<<"Pakistan Studies:";
	gotoxy(45,20); cout<<"Engineering Drawing:";
	fflush(stdin);
	gotoxy(50,13); getline(cin,n);
	this->setName(n);
	gotoxy(82,13); getline(cin,rn);
	this->setRollNo(rn);
	gotoxy(100,13); cin>>s;
	fflush(stdin);
	gotoxy(63,16); getline(cin,ac);
	this->setC1(ac);
	gotoxy(55,17); getline(cin,c);
	this->setC2(c);
	gotoxy(66,18); getline(cin,es);
	this->setC3(es);
	gotoxy(64,19); getline(cin,ps);
	this->setC4(ps);
	gotoxy(65,20); getline(cin,ed);
	this->setC5(ed);
	string e;
	fout.open("All Detail ME\\.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<e<<"\n";
	fout<<s<<"\n";
	fout<<"\n"<<getName()<<" FIRST SEMESTER RECORD"<<"\nRoll Number: "<<getRollNo()<<"\n\n"<<"Applied Chemistry: "<<getC1()<<"\nCalculus: "<<getC2()<<"\nEngineering Survey-I: "<<getC3()
	<<"\nPakistan Studies: "<<getC4()<<"\nEngineering Drawing: "<<getC5()<<"\n\n***\n\n";
	fout.close();
	ofstream fm( ("All Detail ME\\"+getName()+".txt").c_str() );
	fm<<"\n"<<getName()<<" FIRST SEMESTER GPA TRANSCRIPT"<<"\n\n"<<"Applied Chemistry: "<<getC1()<<"\nCalculus: "<<getC2()<<"\nEngineering Survey-I: "<<getC3()
	<<"\nPakistan Studies: "<<getC4()<<"\nEngineering Drawing: "<<getC5()<<"\n\n***\n\n";
	fm.close();
	clear_Area(45,11,113,15);
	gotoxy(45,15);
	cout<<"Press any key to return"; getch();
	ned.setMEAttendance();
}
void Admin::setEEGPA(){
	clear_Area(45,11,113,15);
	gpacs:
	Admin ned;
	string bee,ap,fe,bme,c,s,n,rn;
	ofstream fout;
	ifstream fin;
	gotoxy(45,13); cout<<"Name:";
	gotoxy(70,13); cout<<"Roll Number:";
	gotoxy(90,13); cout<<"Username:";
	gotoxy(95,14); cout<<"GPA SECTION";
	gotoxy(45,16); cout<<"Basic Electrical Engineering:";
	gotoxy(45,17); cout<<"Applied Physics:";
	gotoxy(45,18); cout<<"Functional English:";
	gotoxy(45,19); cout<<"Basic Mechanical Engineering:";
	gotoxy(45,20); cout<<"Calculus:";
	fflush(stdin);
	gotoxy(50,13); getline(cin,n);
	this->setName(n);
	gotoxy(82,13); getline(cin,rn);
	this->setRollNo(rn);
	gotoxy(100,13); cin>>s;
	fflush(stdin);
	gotoxy(75,16); getline(cin,bee);
	this->setC1(bee);
	gotoxy(61,17); getline(cin,ap);
	this->setC2(ap);
	gotoxy(63,18); getline(cin,fe);
	this->setC3(fe);
	gotoxy(75,19); getline(cin,bme);
	this->setC4(bme);
	gotoxy(54,20); getline(cin,c);
	this->setC5(c);
	string e;
	fout.open("All Detail EE\\.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<e<<"\n";
	fout<<s<<"\n";
	fout<<"\n"<<getName()<<" FIRST SEMESTER RECORD"<<"\nRoll Number: "<<getRollNo()<<"\n\n"<<"Basic Electrical Engineering: "<<getC1()<<"\nApplied Physics: "<<getC2()<<"\nFunctional English: "<<getC3()
	<<"\nBasic Mechanical Engineering: "<<getC4()<<"\nCalculus: "<<getC5()<<"\n\n***\n\n";
	fout.close();
	ofstream fm( ("All Detail EE\\"+getName()+".txt").c_str() );
	fm<<"\n"<<getName()<<" FIRST SEMESTER GPA TRANSCRIPT"<<"\n\n"<<"Basic Electrical Engineering: "<<getC1()<<"\nApplied Physics: "<<getC2()<<"\nFunctional English: "<<getC3()
	<<"\nBasic Mechanical Engineering: "<<getC4()<<"\nCalculus: "<<getC5()<<"\n\n***\n\n";
	fm.close();
	clear_Area(45,11,113,15);
	gotoxy(45,15);
	cout<<"Press any key to return"; getch();
	ned.setEEAttendance();
}
void Admin::setSEGPA(){
	clear_Area(45,11,113,15);
	gpase:
	Admin ned;
	string pl,fit,ds,fe,c,ps,s,n,rn;
	ofstream fout;
	ifstream fin;
	gotoxy(45,13); cout<<"Name:";
	gotoxy(70,13); cout<<"Roll Number:";
	gotoxy(90,13); cout<<"Username:";
	gotoxy(95,14); cout<<"GPA SECTION";
	gotoxy(45,16); cout<<"Programming Languages:";
	gotoxy(45,17); cout<<"Fundamentals Of Information Tech:";
	gotoxy(45,18); cout<<"Discrete Structures:";
	gotoxy(45,19); cout<<"Functional English:";
	gotoxy(45,20); cout<<"Calculus:";
	gotoxy(45,21); cout<<"Pakistan Studies:";
	fflush(stdin);
	gotoxy(50,13); getline(cin,n);
	this->setName(n);
	gotoxy(82,13); getline(cin,rn);
	this->setRollNo(rn);
	gotoxy(100,13); cin>>s;
	fflush(stdin);
	gotoxy(67,16); getline(cin,pl);
	this->setC1(pl);
	gotoxy(78,17); getline(cin,fit);
	this->setC2(fit);
	gotoxy(65,18); getline(cin,ds);
	this->setC3(ds);
	gotoxy(64,19); getline(cin,fe);
	this->setC4(fe);
	gotoxy(54,20); getline(cin,c);
	this->setC5(c);
	gotoxy(62,21); getline(cin,ps);
	this->setC6(ps);
	string e;
	fout.open("All Detail CS\\GPA.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<e<<"\n";
	fout<<s<<"\n";
	fout<<"\n"<<getName()<<" FIRST SEMESTER RECORD"<<"\nRoll Number: "<<getRollNo()<<"\n\n"<<"Programming Languages: "<<getC1()<<"\nFundamentals Of Information Tech: "<<getC2()<<"\nDiscrete Structures: "<<getC3()
	<<"\nFunctional English: "<<getC4()<<"\nCalculus:"<<getC5()<<"\nPakistan Studies: "<<getC6()<<"\n\n***\n\n";
	fout.close();
	ofstream fm( ("All Detail CS\\"+getName()+".txt").c_str() );
	fm<<"\n"<<getName()<<" FIRST SEMESTER GPA TRANSCRIPT"<<"\n\n"<<"Programming Languages: "<<getC1()<<"\nFundamentals Of Information Tech: "<<getC2()<<"\nDiscrete Structures: "<<getC3()
	<<"\nFunctional English: "<<getC4()<<"\nCalculus:"<<getC5()<<"\nPakistan Studies: "<<getC6()<<"\n\n***\n\n";
	fm.close();
	clear_Area(45,11,113,15);
	gotoxy(45,15);
	cout<<"Press any key to return"; getch();
	ned.setSEAttendance();
}
void Admin::setCSGPA(){
	clear_Area(45,11,113,15);
	gpacs:
	Admin ned;
	string pl,fit,dic,be,is,s,n,rn;
	ofstream fout;
	ifstream fin;
	gotoxy(45,13); cout<<"Name:";
	gotoxy(70,13); cout<<"Roll Number:";
	gotoxy(90,13); cout<<"Username:";
	gotoxy(45,14); printLineSlowly('|', 49, 5);
	gotoxy(94,14); printStringSlowly(" FIRST SEMESTER GPA ", 5);
	gotoxy(115,14); printLineSlowly('|', 49, 5);
	//fin.open("All Detail CS\\GPA.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	gotoxy(45,16); cout<<"Programming Languages:";
	gotoxy(45,17); cout<<"Fundamentals Of Information Tech:";
	gotoxy(45,18); cout<<"Differential & Integral Calculus:";
	gotoxy(45,19); cout<<"Basic Electronics:";
	gotoxy(45,20); cout<<"Islamic Studies:";
	fflush(stdin);
	gotoxy(50,13); getline(cin,n);
	this->setName(n);
	gotoxy(82,13); getline(cin,rn);
	this->setRollNo(rn);
	gotoxy(100,13); cin>>s;
	fflush(stdin);
	gotoxy(67,16); getline(cin,pl);
	this->setC1(pl);
	gotoxy(78,17); getline(cin,fit);
	this->setC2(fit);
	gotoxy(79,18); getline(cin,dic);
	this->setC3(dic);
	gotoxy(64,19); getline(cin,be);
	this->setC4(be);
	gotoxy(62,20); getline(cin,is);
	this->setC5(is);
	string e;
	fout.open("All Details CS\\GPA.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<e<<"\n";
	fout<<s<<"\n";
	fout<<"\n"<<getName()<<" FIRST SEMESTER RECORD"<<"\nRoll Number: "<<getRollNo()<<"\n\n"<<"Programming Languages: "<<getC1()<<"\nFundamentals Of Information Tech: "<<getC2()<<"\nDifferential & Integral Calculus: "<<getC3()
	<<"\nBasic Electronics: "<<getC4()<<"\nIslamic Studies: "<<getC5()<<"\n\n***\n\n";
	ofstream fm( ("All Details CS\\"+getName()+".txt").c_str() );
	fm<<"\n"<<getName()<<" FIRST SEMESTER GPA TRANSCRIPT"<<"\n\n"<<"Data Structures Algorithm and Application: "<<getC1()<<"\nObject Oriented Programming: "<<getC2()<<"\nDiscrete Structures: "<<getC3()
	<<"\nFunctional English: "<<getC4()<<"\nPakistan Studies: "<<getC5()<<"\n\n***\n\n";
	fout.close();
	fm.close();
	clear_Area(45,11,113,15);
	gotoxy(45,15);
	cout<<"Press any key to proceed"; getch();
	ned.setCSttendance();
}
void Admin::setCSEGPA(){
	clear_Area(45,11,113,15);
	gpacse:
	Admin ned;
	string fec,cp,bee,c,fe,ps,s,n,rn;
	ofstream fout;
	ifstream fin;
	gotoxy(45,13); cout<<"Name:";
	gotoxy(70,13); cout<<"Roll Number:";
	gotoxy(90,13); cout<<"Username:";
	gotoxy(95,14); cout<<"GPA SECTION";
	gotoxy(45,16); cout<<"Fundamentals Of Computer Engineering:";
	gotoxy(45,17); cout<<"Computer Programming:";
	gotoxy(45,18); cout<<"Basic Electrical Engineering:";
	gotoxy(45,19); cout<<"Calculus:";
	gotoxy(45,20); cout<<"Functional English:";
	gotoxy(45,21); cout<<"Pakistan Studies:";
	fflush(stdin);
	gotoxy(50,13); getline(cin,n);
	this->setName(n);
	gotoxy(82,13); getline(cin,rn);
	this->setRollNo(rn);
	gotoxy(100,13); cin>>s;
	fflush(stdin);
	gotoxy(83,16); getline(cin,fec);
	this->setC1(fec);
	gotoxy(66,17); getline(cin,cp);
	this->setC2(cp);
	gotoxy(75,18); getline(cin,bee);
	this->setC3(bee);
	gotoxy(54,19); getline(cin,c);
	this->setC4(c);
	gotoxy(63,20); getline(cin,fe);
	this->setC5(fe);
	gotoxy(63,21); getline(cin,ps);
	this->setC6(ps);
	string e;
	fout.open("All Detail CSE\\.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<e<<"\n";
	fout<<s<<"\n";
	fout<<"\n"<<getName()<<" FIRST SEMESTER RECORD"<<"\nRoll Number: "<<getRollNo()<<"\n\n"<<"Fundamentals Of Computer Engineering: "<<getC1()<<"\nComputer Programming: "<<getC2()<<"\nBasic Electrical Engineering: "<<getC3()
	<<"\nCalculus: "<<getC4()<<"\nFunctional English: "<<getC5()<<"\nPakistan Studies"<<getC6()<<"\n\n***\n\n";
	fout.close();
	ofstream fm( ("All Detail CSE\\"+getName()+".txt").c_str() );
	fm<<"\n"<<getName()<<" FIRST SEMESTER GPA TRANSCRIPT"<<"\n\n"<<"Fundamentals Of Computer Engineering: "<<getC1()<<"\nComputer Programming: "<<getC2()<<"\nBasic Electrical Engineering: "<<getC3()
	<<"\nCalculus: "<<getC4()<<"\nFunctional English: "<<getC5()<<"\nPakistan Studies"<<getC6()<<"\n\n***\n\n";
	fm.close();
	clear_Area(45,11,113,15);
	gotoxy(45,15);
	cout<<"Press any key to return"; getch();
	ned.setCSEAttendance();
}

/*********************************************************** NORMAL FUNCTIONS ************************************************************/
void exit_menu(){
	clear_Area(0,0,200,50);
	Sleep(4000);
	gotoxy(85,9);
	cout<<"UNTIL WE MEET AGAIN !";
	exit(0);
}


void gotoxy(int x, int y){ 
	COORD coord; 
 	coord.X = x;
 	coord.Y = y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int t(void){
	time_t t;
	time(&t);
	cout<<ctime(&t);
	return 0 ;
}

void timetable_design(){
	system("cls");
	int j=45,k=10,i,z=10,v=70,x=46,m=15,a=46;
	char week[5][10]={"MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY"};
	char time[10][15]={"8:30-9:20","9:20-10:10","10:10-11:00","11:00-11:20","11:20-12:10","12:10-01:00","01:00-02:00","02:00-02:50","02:50-3:40","03:40-04:30"};
	gotoxy(j,k);
	for(i=0;i<=110;i++)
	cout<<"|";
	for(i=0;i<=24;i++){
		gotoxy(j,++k); cout<<"|";
	}
	gotoxy(j,35); 
	for(i=0;i<=110;i++){
		cout<<"|";
	}
	for(i=0;i<=24;i++){
	gotoxy(155,++z); cout<<"|";
	}
	gotoxy(46,11); cout<<"SECTION-A";
	gotoxy(46,13); cout<<"TIMING/DAYS";
	for(i=0;i<5;i++){
	 	 gotoxy(v,13); cout<<week[i];
		 v=v+18;
	}
	for(i=0;i<=108;i++){
		gotoxy(x++,14); cout<<"_";
	}
	for(i=0;i<10;i++){
		gotoxy(47,m); cout<<time[i];
		m=m+2;
	}
	for(i=0;i<=108;i++){
		gotoxy(a++,16); cout<<"_";
	}
	a=46;
	for(i=0;i<=108;i++){
		gotoxy(a++,18); cout<<"_";
	}
	a=46;
	for(i=0;i<=108;i++){
		gotoxy(a++,20); cout<<"_";
	}
	a=46;
	for(i=0;i<=108;i++){
		gotoxy(a++,22); cout<<"_";
	}
	a=46;
	for(i=0;i<=108;i++){
		gotoxy(a++,24); cout<<"_";
	}
	a=46;
	for(i=0;i<=108;i++){
		gotoxy(a++,26); cout<<"_";
	}
	a=46;
	for(i=0;i<=108;i++){
		gotoxy(a++,28); cout<<"_";
	}
	a=46;
	for(i=0;i<=108;i++){
		gotoxy(a++,30); cout<<"_";
	}
	a=46;
	for(i=0;i<=108;i++){
		gotoxy(a++,32); cout<<"_";
	}
	gotoxy(45,37); cout<<"Press any key to continue";
	getch();
	system("cls");
}

void printLine(char l,int k){
	for(int i=0;i<k;i++){
		cout<<l;
	}
}

void boxOperation(char l,int height,int width,int x ,int y,void (*functionPtr)(char,int ,int,int,int )){
	(*functionPtr)(l,height,width,x,y);
}
void printSquareBox(char l,int height,int width,int x ,int y){
	if(width>=200 ){
		width=180;
	}
	if(y>=140 ){
		y=100;
	}
	if(height>=80){
		height=70;
	}
	if(x>=60){
		x=50;
	}
	gotoxy(x,y++);
	for(int i=1;i<=height;i++){
		for(int j=1;j<=width;j++){
			if(i==height || i==1 || i==height-1 || i==2 || i==height-2 || i==3 || i==height-3 || i==4 ){
				cout<<l;
			}
			else
			{
				if( j==1 || j==width || j==2 || j==width-1 || j==3 || j==width-2 || j==4 || j==width-3 || j==5 || j==width-4){
					cout<<l;
				}
				else{
					cout<<" ";
				}
			}
		}
		cout<<endl;
		gotoxy(x,y++);
	}	
}

void printTirchaBox(char l,int height,int width,int x ,int y){
	if(width>=200 ){
		width=180;
	}
	if(y>=140 ){
		y=100;
	}
	if(height>=80){
		height=70;
	}
	if(x>=60){
		x=50;
	}
	gotoxy(x++,y++);
	for(int i=1;i<=height;i++){
		for(int j=1;j<=width;j++){
			if(i==height || i==1 || i==height-1 || i==2 || i==height-2 || i==3 || i==height-3 || i==4 || i==height-4 || i==5 ){
				cout<<l;
			}
			else
			{
				if( j==1 || j==width || j==2 || j==width-1 || j==3 || j==width-2 || j==4 || j==width-3 || j==5 || j==width-4){
					cout<<l;
				}
				else{
					cout<<" ";
				}
			}
		}
		cout<<endl;
		gotoxy(x++,y++);
	}	
}


void printStringSlowly(string s, int t){
	int len = s.length();
	for(int i=0;i<len;i++){
		delay(t);
		cout<<s[i];
	}
}

void clear_Area(int x, int y, int width, int height){
	int x1 = x;
	for (int i = 1; i <= height; i++){
		for (int j = 1; j <= width; j++){
			gotoxy(x,y); cout<<" ";
			x++;
		}
		x = x1;
		y++;
	}
}


void print_thankYou(int x, int y){
	gotoxy(x,y); cout<<"UNTIL WE MEET AGAIN !";
}

void login(){
	clear_Area(45,11,119,15);
	gotoxy(85,16); printStringSlowly("LOGGING IN",5);
	for (int i = 1; i <= 2 ;i++){
		gotoxy(96,16); cout<<"      ";
		gotoxy(96,16); printLineSlowly('.',6,300);
 }
	
	clear_Area(45,11,118,15);
}
void logout(){
	clear_Area(45,11,119,15);
	gotoxy(85,16); printStringSlowly("LOGGING OUT",5);
	for (int i = 1; i <= 2; i++){
		gotoxy(96,16); cout<<"      ";
		gotoxy(96,16); printLineSlowly('.',6,300);
}
	clear_Area(45,11,118,15);
}

void printLineSlowly(char l,int k,int t){
	for(int i=0;i<k;i++){
		delay(t);
		cout<<l;
	}
}

void delay (unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void mainmenu(){
	boxOperation('|',25,160,24,7,printSquareBox);
	gotoxy(45,12); printLineSlowly('|',50,5);
	gotoxy(95,12); printStringSlowly("PASSWORD PROTECTED", 5);
	gotoxy(114,12); printLineSlowly('|',50,5);
	Password("ENTER PASSWORD: ");
	mainmenu_student_admin();	
}

void mainmenu_student_admin(){
	boxOperation('|',25,160,24,7,printSquareBox);
	gotoxy(45,12); printLineSlowly('|', 49, 5);
	gotoxy(94,12); printStringSlowly("WELCOME TO NED PORTAL", 5);
	gotoxy(115,12); printLineSlowly('|', 49, 5);
	gotoxy(57,18); cout<<"                            ";
	gotoxy(45,14); cout<<"1. FOR STUDENTS";
	gotoxy(45,15); cout<<"2. FOR ADMIN";
	gotoxy(45,16); cout<<"3. EXIT OR PRESS";
	gotoxy(45,18); cout<<"CHOOSE ONE: ";
	char ch;
	ch = getch();
	if(ch == 27){
		exit_menu();
	}
	switch(ch){
		case '1':
			mainmenu_students();
			break;
		case '2':
			mainmenu_admin();
			break;
		case '3':
			gotoxy(1,35);
			exit_menu();
		default:
			gotoxy(57,20); cout<<"WRONG ENTRY. ";
			getch();
			mainmenu_student_admin();
	}
	
}

void mainmenu_students(){
	char ch;
	boxOperation('|',25,160,24,7,printSquareBox);
	gotoxy(45,12); printLineSlowly('|', 49, 5);
	gotoxy(94,12); printStringSlowly(" STUDENTS SECTION", 5);
	gotoxy(115,12); printLineSlowly('|', 49, 5);
	gotoxy(45,13); cout<<"Press any key to Start or Backspace to go Back";
	ch = getch();
	if (ch == 8){
		mainmenu_student_admin();
	}
	else{
		clear_Area(45,13,125,14);
		Student s;
		Admin uet;
		choose:
		char select;
		gotoxy(45,12); printLineSlowly('|', 49, 5);
		gotoxy(94,12); printStringSlowly(" STUDENTS SECTION  ", 5);
		gotoxy(115,12); printLineSlowly('|', 49, 5);
		gotoxy(94,14); cout<<"SELECT DEPARTMENT";
		gotoxy(45,15); cout<<"1. MECHANICAL ENGINEERING";
		gotoxy(45,16); cout<<"2. ELECTRICAL ENGINEERING";
		gotoxy(45,17); cout<<"3. SOFTWARE ENGINEERING";
		gotoxy(45,18); cout<<"4. COMPUTER SCIENCE AND INFORMATION TECHNOLOGY";
		gotoxy(45,19); cout<<"5. COMPUTER AND INFO SYSTEM ENGINEERING";
		gotoxy(45,20); cout<<"CHOOSE ONE";
		select=getch();
		switch(select){
			case '1':
				clear_Area(45,13,115,11);
				mes:
				gotoxy(45,12); printLineSlowly('|', 49, 5);
				gotoxy(94,12); printStringSlowly(" STUDENT SECTION ", 5);
				gotoxy(115,12); printLineSlowly('|', 49, 5);
				char m;
				gotoxy(45,15); cout<<"1. SHOW INFORMATION";
				gotoxy(45,16); cout<<"2. SHOW ATTENDANCE";
				gotoxy(45,17); cout<<"3. LECTURE NOTES";
				gotoxy(45,18); cout<<"4. PRINT GPA TRANSCRIPT";
				gotoxy(45,19); cout<<"5. SHOW TIME TABLE";
				gotoxy(45,20); cout<<"6. DOWNLOAD COURSE OUTLINE";
				gotoxy(45,21); cout<<"7. GO BACK";
				m=getch();
				if(m=='7'){
					goto choose;
				}
				switch(m){
					case '1':
						s.showDetailsME();
						clear_Area(45,13,115,11);
						goto mes;
						break;
					case '2':
						s.printMEattendance();
						clear_Area(45,13,115,11);
						goto mes;
						break;
					case '3':
						clear_Area(45,13,115,11);
						goto mes;
						break;
					case '4':
						s.printGPA();
						clear_Area(45,13,115,11);
						goto mes;
						break;
					case '5':
						clear_Area(45,13,115,11);
						goto mes;
						break;
					case '6':
						s.printMECourseOutline();
						clear_Area(45,13,115,11);
						goto mes;
						break;
					default:
						gotoxy(45,18); cout<<"Invalid Entry";
						goto mes;
				}
			case '2':
				clear_Area(45,13,115,11);
				ees:
				gotoxy(45,12); printLineSlowly('|', 49, 5);
				gotoxy(94,12); printStringSlowly(" STUDENT SECTION ", 5);
				gotoxy(115,12); printLineSlowly('|', 49, 5);
				char e;
				gotoxy(45,15); cout<<"1. SHOW INFORMATION";
				gotoxy(45,16); cout<<"2. SHOW ATTENDANCE";
				gotoxy(45,17); cout<<"3. LECTURE NOTES";
				gotoxy(45,18); cout<<"4. PRINT GPA TRANSCRIPT";
				gotoxy(45,19); cout<<"5. SHOW TIME TABLE";
				gotoxy(45,20); cout<<"6. DOWNLOAD COURSE OUTLINE";
				gotoxy(45,21); cout<<"7. GO BACK";
				e=getch();
				if(e=='7'){
					goto choose;
				}
				switch(e){
					case '1':
						s.showDetailsEE();
						clear_Area(45,13,115,11);
						goto ees;
						break;
					case '2':
						s.printEEattendance();
						clear_Area(45,13,115,11);
						goto ees;
						break;
					case '3':
						clear_Area(45,13,115,11);
						goto ses;
						break;
					case '4':
						s.printGPA();
						clear_Area(45,13,115,11);
						goto ees;
						break;
					case '5':
						clear_Area(45,13,115,11);
						goto ses;
						break;
					case '6':
						s.printEECourseOutline();
						clear_Area(45,13,115,11);
						goto ses;
						break;
					default:
						gotoxy(45,18); cout<<"Invalid Entry";
						goto ees;
				}
				//break;
			case '3':
				clear_Area(45,13,115,11);
				ses:
				gotoxy(45,12); printLineSlowly('|', 49, 5);
				gotoxy(94,12); printStringSlowly(" STUDENT SECTION ", 5);
				gotoxy(115,12); printLineSlowly('|', 49, 5);
				char w;
				gotoxy(45,15); cout<<"1. SHOW INFORMATION";
				gotoxy(45,16); cout<<"2. SHOW ATTENDANCE";
				gotoxy(45,17); cout<<"3. LECTURE NOTES";
				gotoxy(45,18); cout<<"4. PRINT GPA TRANSCRIPT";
				gotoxy(45,19); cout<<"5. SHOW TIME TABLE";
				gotoxy(45,20); cout<<"6. DOWNLOAD COURSE OUTLINE";
				gotoxy(45,21); cout<<"7. GO BACK";
				w=getch();
				if(w=='7'){
					goto choose;
				}
				switch(m){
					case '1':
						s.showDetailsSE();
						clear_Area(45,13,115,11);
						goto ses;
						break;
					case '2':
						s.printSEattendance();
						clear_Area(45,13,115,11);
						goto ses;
						break;
					case '3':
						
						clear_Area(45,13,115,11);
						goto ses;
						break;
					case '4':
						s.printGPA();
						clear_Area(45,13,115,11);
						goto ses;
						break;
					case '5':
						clear_Area(45,13,115,11);
						goto ses;
						break;
					case '6':
						clear_Area(45,13,115,11);
						goto ses;
						break;
					default:
						gotoxy(45,18); cout<<"Invalid Entry";
						goto ses;
				}
				//break;
			case '4':
				clear_Area(45,11,113,15);
				css:
				Courses cour;
				boxOperation('|',25,160,24,7,printSquareBox);				
				gotoxy(45,12); printLineSlowly('|', 49, 5);
				gotoxy(94,12); printStringSlowly(" STUDENT SECTION ", 5);
				gotoxy(115,12); printLineSlowly('|', 49, 5);
				char c;
				gotoxy(45,15); cout<<"1. SHOW INFORMATION";
				gotoxy(45,16); cout<<"2. SHOW ATTENDANCE";
				gotoxy(45,17); cout<<"3. LECTURE NOTES";
				gotoxy(45,18); cout<<"4. PRINT GPA TRANSCRIPT";
				gotoxy(45,19); cout<<"5. SHOW TIME TABLE";
				gotoxy(45,20); cout<<"6. DOWNLOAD COURSE OUTLINE";
				gotoxy(45,21); cout<<"7. GO BACK";
				c=getch();
				if(c=='7'){
					goto choose;
				}
				switch(c){
					case '1':
						s.showDetailsCS();
						clear_Area(45,13,115,11);
						goto css;
						break;
					case '2':
						s.printCSattendance();
						clear_Area(45,13,115,11);
						goto css;
						break;
					case '3':
						cour.printCSCourses();
						clear_Area(45,13,115,11);
						goto css;
						break;
					case '4':
						s.printGPA();
						clear_Area(45,13,115,11);
						goto css;
						break;
					case '5':
						s.viewCStable();
						clear_Area(45,13,115,11);
						goto css;
						break;
					case '6':
						s.printCSCourseOutline();						
						clear_Area(45,13,115,11);
						goto css;
						break;
					default:
						gotoxy(45,18); cout<<"Invalid Entry";
						goto css;
						break;
				}
			case '5':
				clear_Area(45,11,113,15);
				cses:
				gotoxy(45,12); printLineSlowly('|', 49, 5);
				gotoxy(94,12); printStringSlowly(" STUDENT SECTION ", 5);
				gotoxy(115,12); printLineSlowly('|', 49, 5);
				char j;
				gotoxy(45,15); cout<<"1. SHOW INFORMATION";
				gotoxy(45,16); cout<<"2. SHOW ATTENDANCE";
				gotoxy(45,17); cout<<"3. LECTURE NOTES";
				gotoxy(45,18); cout<<"4. PRINT GPA TRANSCRIPT";
				gotoxy(45,19); cout<<"5. SHOW TIME TABLE";
				gotoxy(45,20); cout<<"6. DOWNLOAD COURSE OUTLINE";
				gotoxy(45,21); cout<<"7. GO BACK";
				j=getch();
				if(j=='3'){
					goto choose;
				}
				switch(c){
					case '1':
						s.showDetailsCSE();
						clear_Area(45,13,115,11);
						goto cses;
						break;
					case '2':
						s.printCSEattendance();
						clear_Area(45,13,115,11);
						goto cses;
						break;
					case '3':
						clear_Area(45,13,115,11);
						goto ses;
						break;
					case '4':
						s.printGPA();
						clear_Area(45,13,115,11);
						goto cses;
						break;
					case '5':
						clear_Area(45,13,115,11);
						goto ses;
						break;
					case '6':
						clear_Area(45,13,115,11);
						goto ses;
						break;
					default:
						gotoxy(45,18); cout<<"Invalid Entry";
						goto cses;
						break;
				}
				//break;
			default:
				gotoxy(45,21); cout<<"Invalid Entry";
				goto choose;
				break;
		}
	}
}

void mainmenu_admin(){
	boxOperation('|',25,160,24,7,printSquareBox);
	gotoxy(45,12); printLineSlowly('|', 49, 5);
	gotoxy(94,12); printStringSlowly(" FOR OFFICE USE ONLY ", 5);
	gotoxy(115,12); printLineSlowly('|', 49, 5);
	Password("ENTER PASSWORD TO UNLOCK DETAILS (OFFICE USE) : ");
	clear_Area(45,13,115,6);
	char ch;
	gotoxy(45,13); cout<<"Press any key to Start or Backspace to go Back";
	gotoxy(45,14); 
	ch = getch();
	if (ch == 8){
		mainmenu();
	}
	mainmenu_admin_panel();
}
void mainmenu_admin_panel(){
	clear_Area(45,11,113,15);
	char ch;
	int i=13,tag=0,y=15;
	string s1,s2,s3,s4;
	ifstream fin1,fin2;
	gotoxy(45,14); 
	Admin an;
	Student s;
	back:
	char choice;
				clear_Area(45,13,115,11);
				gotoxy(45,12); printLineSlowly('|', 49, 5);
				gotoxy(94,12); printStringSlowly(" FOR OFFICE USE ONLY ", 5);
				gotoxy(115,12); printLineSlowly('|', 49, 5);
				gotoxy(45,14);
				cout<<"1. VIEW DETAILS ";
				gotoxy(45,15);
				cout<<"2. ADD DETAILS ";
				gotoxy(45,16);
				cout<<"3. GO BACK ";
				gotoxy(45,17);
				cout<<"4. EXIT ";
				gotoxy(45,19);
				cout<<"CHOOSE ONE ";
				choice=getch();
				if(ch=='3'){
					mainmenu_admin();
				}
				switch(choice){
					case '1':
						clear_Area(45,13,115,11);
						gotoxy(45,12); printLineSlowly('|', 49, 5);
						gotoxy(94,12); printStringSlowly(" FOR OFFICE USE ONLY ", 5);
						gotoxy(115,12); printLineSlowly('|', 49, 5);
						hi:
						char d;
						gotoxy(45,15);
						cout<<"1. View Details of Students ";
						gotoxy(45,16);
						cout<<"2. View Details of Teachers ";
						gotoxy(45,17);
						cout<<"3. View Semester Details ";
						gotoxy(45,18);
						cout<<"4. Go Back ";
						gotoxy(45,19);
						cout<<"Enter your choice ";
						d=getch();
						switch(d){
							case '1':
								an.selectDepartment();
								break;
							case '2':		
								break;
							case '3':
								break;
							default:
								cout<<"Invalid Entry. Try Again";
								goto hi;
						}
					case '2':
						clear_Area(45,13,111,15);
						gotoxy(45,12); printLineSlowly('|', 49, 5);
						gotoxy(94,12); printStringSlowly(" FOR OFFICE USE ONLY ", 5);
						gotoxy(115,12); printLineSlowly('|', 49, 5);
						char c;
						gotoxy(45,15);
						cout<<"1. Add Student";
						gotoxy(45,16);
						cout<<"2. Add Teacher";
						gotoxy(45,17);
						cout<<"3. Go Back";
						gotoxy(45,18);
						cout<<"Choose One";
						c=getch();
						switch(c){
							case '1':
								an.registerStudent();
								break;
							default:
								gotoxy(45,22);
								cout<<"Invalid Entry. Try Again";
								//goto wow;								
						}
					case '3':
						break;
					case '4':
						exit_menu();
					default:
						gotoxy(45,21); cout<<"Invalid Entry";
						goto back;
}
}

/*********************************************************** MAIN FUNCTION ***************************************************************/
int main(){
	system("mode con: cols=200 lines=80");
	HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd,SW_SHOWMAXIMIZED);
    gotoxy(90,2);
    cout<<"Starting Time Of Program";
    gotoxy(90,4);
    t();
    mainmenu();
	return 0;
}
