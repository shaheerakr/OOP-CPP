#include<iostream>
using namespace std;

template <class data>
data add(data num1,data num2)
{
	return num1+num2;
}
int main()
{
	int v1=10,v2=20,v3;
	v3=add(v1,v2);
	cout<<v3;
	return 0;
}
