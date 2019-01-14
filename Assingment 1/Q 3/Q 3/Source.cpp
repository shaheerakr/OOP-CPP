#include<iostream>
#define pi 3.14
using namespace std;

class shape
{
public:
	float area(int rad)
	{
		return pi * rad*rad;
	}
	float area(int len, int bregth)
	{
		return len * bregth;
	}
};

int main()
{
	shape fig;
	cout <<"circle"<< fig.area(9)<<endl;
	cout <<"rect"<< fig.area(3, 5)<<endl;
	system("pause");
}