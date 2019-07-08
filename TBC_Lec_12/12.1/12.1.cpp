#include <iostream>
#include<string>
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

	virtual void speak() const
	{
		cout << _name << " ??? " << endl;
	}
};

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


int main()
{
	Animal animal("my animal");
	Cat cat("my cat");
	Dog dog("my dog");

	animal.speak();
	cat.speak();
	dog.speak();

	Animal* ptr_animal1= &cat;
	Animal* ptr_animal2 = &dog;

	//ptr_animal1->speak(); //포인터로 상속 클래스의 함수를 호출하면 부모클래스의 함수가 호출이됨
	//ptr_animal2->speak();


	Cat cats[] = { Cat("cat1"),Cat("cat2") ,Cat("cat3") ,Cat("cat4") ,Cat("cat5") };
	Dog dogs[] = { Dog("dog1"),Dog("dog2") };

	for (int i = 0; i < 5; ++i)
	{
		cats[i].speak();
	}

	for (int i = 0; i < 2; ++i)
	{
		dogs[i].speak();
	}

	Animal* my_animals[] = {&cats[0],&cats[1] ,&cats[2] ,&cats[3] ,&cats[4],&dogs[0],&dogs[1] };

	for (int i = 0; i < 7; ++i)
	{
		my_animals[i]->speak(); //부모클래스 함수 앞에 virtual 선언을 해주면 상속받은 클래스 함수에 정의된 것을 호출한다
	}
	return 0;
}

