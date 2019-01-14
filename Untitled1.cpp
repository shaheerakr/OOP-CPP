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

class student{
	public:
	void show();
	void deletefind();
};
void student::show(){
	string s,si,su,pass,c3,c4;
	int i=13,tag=0,tag1=0;
	ifstream fin1,fin2;
	fin1.open("CSIT\\Usernames.txt");
	fin2.open("CSIT\\Passwords.txt");
	//clear_Area(45,13,115,14);
	//gotoxy(45,14);
	cout<<"Enter your username : ";
	cin>>s;
	//gotoxy(45,15);
	cout<<"Enter you Password to verify that its you : ";
	cin>>pass;
		while(!fin1.eof() || !fin2.eof()){
			getline(fin1,c3);
			getline(fin2,c4);
			if(s==c3 && pass==c4){
				tag1=1;
				//clear_Area(45,13,115,14);
				ifstream fin;
				fin.open("All Details CS\\all details.txt");
				while(!fin.eof()){
					do{
					fin>>si;
					if(si==s){
						tag=1;
						getline(fin,su);
							while(su!="***"){
							//gotoxy(45,i++);
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
}

void student::deletefind() {
string deleteline;
string line;
ifstream in("All Details CS\\all details.txt");
if (!in.is_open()) {
    cout << "Input file failed to open\n";
}
ofstream out("outfile.txt");
cout << "Please Select the Vessel you would like to remove" << endl;
cin >> deleteline;
while (getline(in, deleteline)) {
    if (line != deleteline)
        out << line << endl;
}
in.close();
out.close();
remove("All Details CS\\all details.txt");
rename("outfile.txt", "All Details CS\\all details.txt");
cout << "\nChanges has Successfully been made"<<endl;
}
int main(){
	student s;
	s.show();
	s.deletefind();
}
