#include<iostream>

using namespace std;

class factorial
{
public:
	int fact(int n)
	{
		if(n==0||n==1)
			return 1;
		else
			return n*fact(n-1);
	}
	char fact(char n)
	{
		if(n==0||n==1)
			return 1;
		else 
			return n*fact(n-1);
	}
	double fact(double n)
	{
		if(n==0||n==1)
			return 1;
		else
			return n*fact(n-1);
	}
	float fact(float n)
	{
		if(n==0||n==1)
			return 1;
		else
			return n*fact(n-1);
	}
}
int main()
{
	int f1;
	char f2;
	float f3;
	double f4;
	
}
