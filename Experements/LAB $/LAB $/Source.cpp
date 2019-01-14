#include<iostream>
using namespace std;
class tollbooth
{
private: int noOfCars;
		 int totalMoney;
public:
	tollbooth()
	{
		noOfCars = 1;
		totalMoney = 10;

	}
	void payingcar()
	{
		noOfCars++;
		totalMoney += 10;
	}
	void nopayingcar()
	{
		noOfCars++;
	}
	void display()
	{
		int option;
		cout << "1. Paying car" << endl << "2. Non Paying car" << endl << "3. total money" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "the number of paying car are: " << (totalMoney / 10) << endl;
			break;
		case 2:
			cout << "the number of non paying cars are: " << noOfCars - (totalMoney / 10) << endl;
			break;
		case 3:
			cout << "total money: " << totalMoney << endl;
			break;
		default:
			break;
		}
	}
};
int main()
{
	tollbooth cars;
	int check;
	cout << "1. Paying car" << endl << "2. non paying car" <<endl<<"3. display"<<endl<<"4. exit"<< endl;
	cin >> check;
	while (check != 4)
	{
		cin >> check;
		switch (check)
		{
		case 1:
			cars.payingcar();
			break;
		case 2:
			cars.nopayingcar();
			break;
		case 3:
			cars.display();
			break;
		default:
			break;
		}
	}
}