#include<iostream>
#include<string>

using namespace std;

class publication
{
private:
	string title;
	float price;
public:
	publication(string tit="", float pri=0):title(tit),price(pri)
	{}
	void getData()
	{
		cout << "enter titel";
		cin >> title;
		cout << "enter price";
		cin >> price;
	}
	void putData()
	{
		cout << "titel: " << title << endl;
		cout << "price: " << price << endl;
	}
};

class Book :public publication
{
private:
	int page;
public:
	Book(int count=0): page(count)
	{}
	void get()
	{
		getData();
		cout << "enter page count";
		cin >> page;
	}
	void put()
	{
		putData();
		cout << "page count: " << page << endl;
	}
};

class Tape :public publication
{
private:
	float playTime;
public:
	Tape(float time=0) :playTime(time)
	{}
	void get()
	{
		getData();
		cout << "enter playing time";
		cin >> playTime;
	}
	void put()
	{
		putData();
		cout << "playing time: " << playTime << endl;
	}
};

int main()
{
	Book b1;
	Tape t1;
	b1.get();
	t1.get();
	b1.put();
	t1.put();
	system("pause");
}