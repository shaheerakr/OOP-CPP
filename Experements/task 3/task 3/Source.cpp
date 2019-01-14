#include<iostream>
#include<string>

using namespace std;

bool anagram(char*, char*);

int main()
{
	char str1[100], str2[100];
	cout << "enter two string to check anagram" << endl;
	cin >> str1 >> str2;
	bool check = anagram(str1, str2);
	if (check == true)
		cout << "this is an anagram" << endl;
	else
		cout << "this is not an anagram" << endl;
	system("pause");
}
bool anagram(char*str1, char*str2)
{
	int size1 = strlen(str1), size2 = strlen(str2), i, j;
	if (size1 == size2)
	{
	}
}