#include<iostream>
#include<string>
using namespace std;
class base
{
private:
	string name="shaheeer";
public:
	virtual string showName()
	{
		return name;
	}
};
class driv:public base
{
private:
	//string name;
public:
	string showName()
	{
		//name=base::showName();
		return base::showName();
	}	
};
int main()
{
	base *ptr = new driv;
	cout<<"name= "<<ptr->showName();
}
