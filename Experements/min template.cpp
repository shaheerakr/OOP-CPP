#include<iostream>
using namespace std;
template <class F,class S>
F min(F num1,S num2)
{
	return (num1<num2?num1:num2);
}
int main()
{
	cout<< min(30.1,3)<<endl;
	return 0;
}
