#include<iostream>
using namespace std;

class car
{
public:
	char colour[10] = "RED";
	cout << "the colour of car is " << colour << endl;
};
int main()
{
	car objcar;
	
	system("pause");
}
