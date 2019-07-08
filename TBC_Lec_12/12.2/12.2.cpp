#include <iostream>
using namespace std;

class A
{
public:
	virtual void print() { cout << "A" << endl; }
};


class B : public A
{
public:
	 void print() { cout << "B" << endl; }
};

class C: public B
{
public:
	void print() { cout << "C" << endl; }
};

//class D : public C
//{
//public:
//	void print() { cout << "D" << endl; }
//};
class D : public C
{
public:
	void print() { cout << "D" << endl;  } //상속해주는 최상위 클래스의 virtual 함수의 return 타입과 동일해야함
};

int main()
{

	A a;
	//a.print();

	B b;
	//b.print();

	C c;
	//c.print();

	D d;
	/*d.print();*/

	A& ref = b; //상속받은 클래스의 함수가 virtual이고 상속받는 클래스에 함수 오버라이딩이 될 경우 상속 받는 클래스에 있는 함수가 호출됨
	ref.print();

	A& ref2 = c; //c클래스가 b클래스를 상속받는 2중 상속 구조임에도 불구하고 A class의 virtual선언 덕분에 c클래스의 함수가 호출됨
	ref2.print();


	B& ref3 = c; //최상위 클래스의 동일한 함수명이 virtual선언인 경우 상속받는 클래스의 함수도 virtual처럼 동작함
	ref3.print();

	/*B& ref2 = c;
	ref2.print();*/


	return 0;
}

