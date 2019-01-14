#include<iostream>
#define pi 3.14
using namespace std;

class circle
{
private:
	int radius;
public:
	circle(int radius=0):radius(radius)
	{}
	float area()
	{
		return pi * radius*radius;
	}
	float circumfernce()
	{
		return 2 * pi*radius;
	}
};
int main()
{
	circle c1(5), c2(7);
	cout << c1.area()<<endl;
	cout << c2.circumfernce() << endl;
	system("pause");
}