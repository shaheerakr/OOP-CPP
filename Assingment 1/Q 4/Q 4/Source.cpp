#include<iostream>
#include<string>

using namespace std;

class student
{
protected:
	int rollNo;
	string name;
public:
	student(int rn=0,string n=""):rollNo(rn),name(n)
	{}
	void getInfo()
	{
		cout << "enter name";
		cin >> name;
		cout << "enter roll no";
		cin >> rollNo;
	}
};
class marks : public student
{
private:
	int sub1, sub2, sub3;
public:
	marks(int s1=0,int s2=0,int s3=0): sub1(s1),sub2(s2),sub3(s3)
	{}
	void getMarks()
	{
		getInfo();
		cout << "enter marks for subject one";
		cin >> sub1;
		cout << "enter marks for subject two";
		cin >> sub2; 
		cout << "enter marks for subject three";
		cin >> sub3;
	}
	void display()
	{
		cout << "name" << name << endl;
		cout << "roll no" << rollNo << endl;
		cout << "marks one" << sub1 << endl;
		cout << "marks two" << sub2 << endl;
		cout << "marks three" << sub3 << endl;
		cout << "total: " << sub1 + sub2 + sub3 << endl;
		cout << "percentage: " << (sub1 + sub2 + sub3) / 3 << endl;
	}
};
int main()
{
	marks st1;
	st1.getMarks();
	st1.display();
	system("pause");
}