#include <iostream>
using namespace std;

class PoweredDevice
{
public:

	int _i;

	PoweredDevice(int power)
	{
		cout << "Powered Device" << power << endl;
	}
};

class Scanner : virtual public PoweredDevice
{
public:
	Scanner(int scanner, int power)
		:PoweredDevice(power)
	{
		cout << "Scanner" << scanner << endl;
	}
};
class Printer : virtual public PoweredDevice
{
public:
	Printer(int printer, int power)
		:PoweredDevice(power)
	{
		cout << "Printer" << printer << endl;
	}
};

class Copier :public Scanner, public Printer
{
public:
	Copier(int scanner , int printer, int power)
		:Scanner(scanner, power), Printer(printer, power), PoweredDevice(power)
	{
		
	}
};
int main()
{

	Copier cop(1, 2, 3);

	cout << &cop.Scanner::PoweredDevice::_i << endl;
	cout << &cop.Printer::PoweredDevice::_i << endl;

	return 0;
}

