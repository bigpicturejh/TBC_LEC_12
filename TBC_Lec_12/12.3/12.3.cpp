#include <iostream>
using namespace std;

class A
{
public:
	 void print()   { cout << "A" << endl; }
	 virtual A* getThis() { 
		 cout << "A::getThis()" << endl;
		 return this; }
};

//class B : public A
//{
//public:
//	void print(int x) const override { cout << "B" << endl; } //override라고 명시해두면 상속해주는 클래스의 함수를 override할 수있도록 컴파일러가 잡아줌
//};

class B : public A
{
public:
	void print()  { cout << "B" << endl; } //B를 상속받는 클래스에서는 <final>선언 때문에 print함수를 오버라이딩 할 수 없게된다
	virtual B* getThis() {
		cout << "B::getThis()" << endl;
		return this; } //return 타입이 다르면 오버라이딩이 안되지만 A클래스와 부모자식 관계이므로 오버라이딩이 가능해짐(이해 안됨)
};

class C : public B
{
public:
	//virtual void print() { cout << "C" << endl; }
};
int main()
{
	A a;
	B b;

	A& ref = b;
	/*ref.print(1);*/

	b.getThis()->print();
	ref.getThis()->print();

	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl;

	return 0;
}

