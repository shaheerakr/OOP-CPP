#include<iostream>
using namespace std;
class add
{
private:
	int feet, inch;
public:
	add(int v1=0, int v2=0) :feet(v1), inch(v2)
	{}
	add operator +(add t)
	{
		add temp;
		temp.feet = feet + t.feet;
		temp.inch = inch + t.inch;
		while (temp.inch >= 12)
		{
				temp.feet++;
				temp.inch -= 12;
		}
		return temp;
	}
	void display()
	{
		cout << feet << " feet " << inch << " inch" << endl;
	}
};
int main()
{
	add m1(2, 7), m2(5, 7), m3;
	m1.display();
	m2.display();
	m3 = m1 + m2;
	m3.display();
	system("pause");
}