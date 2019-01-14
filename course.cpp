#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
using namespace std;
main()
{
	string name;
ifstream fin;
//gotoxy(45,20); 
cout << "Enter lecture title : ";
getline(cin, name);
name = "notepad \"" +name+ "\"";
//clear_Area(45,13,115,11);
//gotoxy(45,15); 
cout<<"Your Lecture Slide is being generated";
//Sleep(4000);
system((name+".txt").c_str());
}
