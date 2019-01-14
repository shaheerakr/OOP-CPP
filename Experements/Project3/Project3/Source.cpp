#include<iostream>
using namespace std;

class Int
{
private:
	int i;
public:
	Int():i(0)
	{}
	Int(int val) :i(val)
	{}
	void add(Int v1, Int v2)
	{
		i = v1.i + v2.i;
	}
	void display()
	{
		cout<< i << endl;
	}
};
int main()
{
	Int int1(5), int2(25), int3;
	int1.display();
	int2.display();
	int3.add(int1, int2);
	int3.display();
	system("pause");
}