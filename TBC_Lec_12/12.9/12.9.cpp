#include <iostream>
#include<vector>
#include<functional>
using namespace std;

class Base
{
public:
	int _i=0;

	virtual void print()
	{
		cout << "Base" << endl;
	}
};

class Derived : public Base
{
public:
	int _j = 1;

	virtual void print() override
	{
		cout << "Derived" << endl;
	}
};

//void ds(Base b) //&없이 복사 대입을 하게되면 부모클래스의 정보만 사용할수 있게되어 다형성이 사라지게 됨
void ds(Base & b)

{
	b.print();
}
int main()
{

	Derived d;
	//Base b = d; //&없이 복사 대입을 하게되면 부모클래스의 정보만 사용할수 있게되어 다형성이 사라지게 됨
	//Base &b = d;
	//
	//b.print();

	/*ds(d);*/

	Base b;

	//vector<Base> my_vec;
	//my_vec.push_back(b);
	//my_vec.push_back(d);//push_back을할때 Base클래스로 슬라이싱이 되어 정보가 누락되는 문제 발생

	//for (auto& idx : my_vec)
	//{
	//	idx.print();
	//}



	vector<Base*> my_vec2; //포인터로 받아주면 슬라이싱 오류가 발생하지 않게됨
	my_vec2.push_back(&b);
	my_vec2.push_back(&d);

	for (auto& idx : my_vec2)
	{
		idx->print();
	}
	
	//vector<Base&> // 아래 줄이 이와같이 작동하게 됨
	vector<reference_wrapper<Base>> my_vec3; //포인터로 받아주면 슬라이싱 오류가 발생하지 않게됨
	my_vec3.push_back(b);
	my_vec3.push_back(d);

	for (auto& idx : my_vec3)
	{
		idx.get().print();//레퍼런스로부터 값을 가져온다는 의미로 get()사용
	}

	return 0;
}

