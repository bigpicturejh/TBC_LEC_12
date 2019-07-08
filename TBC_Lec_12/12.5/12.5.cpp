#include <iostream>
using namespace std;

int add(int x, int y)
{
	return x + y;
}


int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}


int main()
{

	int x, y;
	cin >> x >> y;

	int op;
	cout << "put the input operation" << endl; //assert를 사용해서 입력이 잘못 들어오지 않도록 사전에 방지할 수 있음
	cin >> op;

	// static binding(early binding): 어떤 operation이 수행될지 compile타임에 정해지는 경우
	/*int results;
	switch (op)
	{
	case 0: results = add(x, y); break;
	case 1: results = sub(x, y); break;
	case 2: results = mul(x, y); break;
	}

	cout << results << endl;
*/

	//Dynamic binindg(late binding): runtime에 동작할 operation이 정해지는 경우
	//Static binding보다 실행속도는 느리지만 프로그램을 유연하게 작성할 수 있다는 장점이 있음
	int(*func_ptr)(int, int) = nullptr;
	
	switch (op)
	{
	case 0: func_ptr = add; break;
	case 1: func_ptr = sub; break;
	case 2: func_ptr = mul; break;
	}

	cout << func_ptr(x, y) << endl;
	return 0;
}

