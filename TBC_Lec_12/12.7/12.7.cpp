#include <iostream>
using namespace std;


class Animal
{
protected:
	string _name;

public:
	Animal(string name_in)
		:_name(name_in)
	{

	}

	string getName() { return _name; }

	virtual void speak() const = 0; // Pure virtual function[body가 정의되어 있지 않음], 자식클래스에서 무조건 구현을 해야함!!
	
	/*virtual void speak() const
	{
		cout << _name << " ??? " << endl;
	}*/
};
//void Animal::speak() const // the body of the pure virtual function
//{
//	cout << _name << " ??? " << endl;
//}

class Cat : public Animal
{
public:
	Cat(string name_in)
		:Animal(name_in)
	{

	}

	void speak() const
	{
		cout << _name << " Meow" << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(string name_in)
		:Animal(name_in)
	{
	}

	void speak() const
	{
		cout << _name << "Woof " << endl;
	}

};

class Cow : public Animal
{
public:
	Cow(string name_in)
		:Animal(name_in)
	{
	}
	virtual void speak() const
{
	cout << _name << " Moo " << endl;
}


};


class IErrorLog
{
public:
	virtual bool reportError(const char* errorMessage) = 0;

	virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Writing error to a file" << endl;
		return true;
	}
};

class ConsoleErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Printing error to console" << endl;
		return true;
	}
};

void ds(IErrorLog& log) //인터페이스 클래스를 입력으로 받아서 다양한 종류의 결과를 얻을 수 있도록 함
{
	log.reportError("Runtime Error");
}

int main()
{

	/*Animal ani("Hi");*/ //순수가상함수때문에 클래스 인스턴스 생성이 안됨

	/*Cow cow("so");
	cow.speak();
*/

	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	ds(file_log);
	ds(console_log);


	return 0;
}

