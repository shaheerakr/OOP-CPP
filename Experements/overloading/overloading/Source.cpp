#include<iostream>
#include<string>
using namespace std;
class office
{
private:
	int id, dob, sal;
	string name;
public:
	office()
	{
		name = "";
		id = 0;
		dob = 0;
		sal = 0;
	}
	void set()
	{
		cout << "enter name" << endl;
		cin >> name;
		cout << "enter id" << endl;
		cin >> id;
		cout << "enter date of birth" << endl;
		cin >> dob;
		cout << "enter sallary" << endl;
		cin >> sal;
	}
	void display()
	{
		cout << "name: " << name << endl << "id: " << id << endl << "date of birth: " << dob << endl << "sallary: "<< sal << endl;
	}
};
int main()
{
	office emp1, mang;
	static int check;
	do
	{
		cout << "1.employee\t2.manager\t3.exit" << endl;
		cin >> check;
		switch (check)
		{
		case 1:
			cout << "1.set\t2.display" << endl;
			cin >> check;
			switch (check)
			{
			case 1:
				emp1.set();
				break;
			case 2:
				emp1.display();
				break;
			default:
				break;
			}
			break;
		case 2:
			cout << "1.set\t2.display" << endl;
			cin >> check;
			switch (check)
			{
			case 1:
				mang.set();
				break;
			case 2:
				mang.display();
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	} while (check != 3);
	return 0;
}