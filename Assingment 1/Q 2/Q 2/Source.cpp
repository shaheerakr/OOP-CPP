#include<iostream>
#include<string>
using namespace std;
class str
{
private:
	string st;
public:
	str()
	{
		st = "";
	}
	str(string v)
	{
		st = v;
	}
	str operator + (str v)
	{
		str s;
		s.st = st + v.st;
		return s;
	}
	void display()
	{
		cout << st << endl;
	}
};

int main()
{
	str s1("hello"), s2(" world");
	str s3 = s1 + s2;
	s1.display();
	s2.display();
	s3.display();
	system("pause");
}