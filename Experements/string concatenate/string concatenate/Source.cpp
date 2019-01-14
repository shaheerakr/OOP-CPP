#include<iostream>
#include<string>
using namespace std;
//class string
//{};
int main()
{
	string string1, string2, string3;
	string *s1, *s2, *s3;
	s1 = &string1;
	s2 = &string2;
	s3 = &string3;
	*s1 = "Hello ";
	*s2 = "World";
	*s3 = *s1 + *s2;
	cout << string3 << endl;
	system("pause");
}