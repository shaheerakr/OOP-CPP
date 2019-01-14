#include<iostream>

using namespace std;

class tollbooth
{
private:
	int cars,bikes,vans,amount;
public:
	tollbooth():cars(0),amount(0),bikes(0),vans(0)
	{
	}
	void add()
	{
		int ch=0;
		cout<<"1.Car\t2.bike\t3.van"<<endl;
		cin>>ch;
		if(ch==1)
		{
			amount+=10;
			cars++;
		}
		else if(ch==2)
		{
			amount+=5;
			bikes++;
		}
		else if(ch==3)
		{
			amount+=20;
			vans++;
		}
		else
		{
			cout<<"invalid option";
		}
	}
	void display()
	{
		cout<<"cars: "<<cars<<endl<<"bikes: "<<bikes<<endl<<"vans: "<<vans<<endl<<"amount: "<<amount<<endl;
	}
};

int main()
{
	tollbooth toll; 
	int ch=0;
	while(1)
	{
		cout<<"1.add\t2.display\t3.exit";
		cin>>ch;
		if(ch==1)
		{
			toll.add();
		}
		if(ch==2)
		{
			toll.display();
		}
		if(ch==3)
		{
			break;
		}
	}
	return 0;
}
