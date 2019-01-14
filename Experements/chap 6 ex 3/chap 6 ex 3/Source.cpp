#include<iostream>
using namespace std;

class time
{
private:
	int h, m, s;
public:
	time():h(0),m(0),s(0)
	{}
	time(int v1, int v2, int v3)
	{
		h = v1; 
		m = v2;
		s = v3;
	}
	void display()
	{
		cout << h << ":" << m << ":" << s << endl;
	}
	void add(time t1, time t2)
	{
		h = t1.h + t2.h;
		m = t1.m + t2.m;
		s = t1.s + t2.s;
		while (1)
		{
			if (m >= 60)
			{
				h++;
				m -= 60;
			}
			if (s >= 60)
			{
				m++;
				s -= 60;
			}
			if (m < 60 && s < 60)
				break;
		}
	}
};
int main()
{
	time t1(11,32,55), t2(17,54,36);
	time t3;
	t1.display();
	t2.display();
	t3.add(t1, t2);
	t3.display();
	system("pause");
}