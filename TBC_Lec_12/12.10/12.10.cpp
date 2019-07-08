#include <iostream>
using namespace std;


class Base
{
public:
	int _i = 0;

	virtual void print()
	{
		cout << "Base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int _j = 1024;

	virtual void print() override
	{
		cout << "Derived1" << endl;
	}
};

class Derived2 : public Base
{
public:
	string _name = "Two";

	virtual void print() override
	{
		cout << "Derived2" << endl;
	}
};

int main()
{

	Derived1 d1;
	d1._j = 202020;
	Base* base = &d1;
	
	
	//*****base가 다시 derived1의 형태로 변환이 필요한데 d1의 직접적인 접근이 어려운 경우 해결방법******
	auto* base_to_d1 = dynamic_cast<Derived1*>(base);
	//auto* base_to_d1 = dynamic_cast<Derived2*>(base);
	//auto* base_to_d1 = static_cast<Derived2*>(base); //static_cast도 가능함<Drived2*>인 경우도!. 하지만 dynamic_cast는 runtime에 발생하는 문제를 더 잘 잡아주려는 특성이 있음

	if (base_to_d1 != nullptr) //동적캐스팅이 실패한 경우 nullptr이 들어가게된다(위에서 <Derived2*>로 하는 경우)
	{
		cout << base_to_d1->_j << endl;
		base_to_d1->print();
	}
	else
		cout << "Failed" << endl;
	//base_to_d1->_j = 224;
	//cout << d1._j << endl;

	
	return 0;
}

