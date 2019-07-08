#include <iostream>
using namespace std;

class Base
{
public:
	//FunctionPointer *_vptr;
	 virtual void func1() {};
	 void func2() {};
};

class Der :public Base
{
public:
	//FunctionPointer *_vptr;
	 void func1() {};
	 void func3() {};
};


int main()
{

	cout << sizeof(Base) << endl; //virtual선언을 해주면 virtual 함수 포인터 생성으로 인해 차지하는 메모리의 크기가 증가함
	cout << sizeof(Der) << endl;

	return 0;
}

