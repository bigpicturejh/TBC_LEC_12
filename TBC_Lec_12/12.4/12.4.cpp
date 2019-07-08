#include <iostream>
using namespace std;


class Base
{
public:
	 virtual ~Base()
	{
		cout << "~Base" << endl;
	}
};


class Derived : public Base
{
private:
	int* _array;

public:
	Derived(int length)
	{
		_array = new int[length];
	}

	~Derived() 
	{
		cout << "~Derived" << endl;
		delete[] _array;
	}
};

int main()
{

	//Derived derived(5);

	Derived* derived = new Derived(5);
	Base* base = derived;
	delete base; //상속해주는 Base클래스의 소멸자 앞에 virtual선언이 없을 경우 상속받은 Derived클래스의 소멸자는 호출되지 않게됨

	return 0;
}

