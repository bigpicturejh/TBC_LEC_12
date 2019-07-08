#include <iostream>
using namespace std;

class Base
{
public:
	Base() {}

	friend ostream& operator <<(ostream& out, const Base& b)
	{
		return b.print(out);
	}
	
	virtual ostream& print(ostream& out)const
	{
		out << "Base";
		return out;
	}
};


class Derived :public Base
{
public:
	Derived() {}

	virtual ostream& print(ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};

int main()
{

	Base b;
	cout << b << endl;

	Derived d;
	cout << d << endl;

	Base& ref = d;
	cout << ref << endl; //Base클래스 레퍼런스로 받아졌지만 다형성 때문에 Derived클래스의 print함수가 호출됨
	

	return 0;
}

