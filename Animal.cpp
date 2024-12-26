#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <memory>

using namespace std;
class Animal
{
public:
	virtual void MakeSound() = 0;

};

class Dog : public Animal
{
public:
	void MakeSound() override
	{
		cout << "°³°¡ ¿Ð¿Ð!" << endl;
	}
};

class Cat : public Animal
{
public:
	void MakeSound() override
	{
		cout << "°í¾çÀÌ°¡ ¾ß¾Æ¾Æ¾Æ¿À¿Ë~" << endl;
	}
};

class Tiger : public Animal
{
public:
	void MakeSound() override
	{
		cout << "È£¶ûÀÌ°¡ ¾îÈåÀÀ~" << endl;
	}
};

class Lion : public Animal
{
public:
	void MakeSound() override
	{
		cout << "»çÀÚ°¡ Äí¾î¾î¾û!" << endl;
	}
};

class Zoo
{
private:
	vector<unique_ptr<Animal>> Animals;

public:
	void AddAnimal(unique_ptr<Animal> Animal)
	{
		Animals.push_back(move(Animal));
	}

	void PerformAction()
	{
		for (vector<unique_ptr<Animal>>::iterator it = Animals.begin(); it != Animals.end(); ++it)
		{
			(*it)->MakeSound();
		}
	}

	unique_ptr<Animal> CreateRandomAnimal()
	{
		int RandomNumber = rand() % 4;
		
		switch (RandomNumber)
		{
		case 0: return make_unique<Dog>();
		case 1: return make_unique<Cat>();
		case 2: return make_unique<Tiger>();
		case 3: return make_unique<Lion>();
		}
	}

	~Zoo() = default;
};

int main()
{
	Zoo zoo;
	zoo.AddAnimal(zoo.CreateRandomAnimal());
	zoo.AddAnimal(zoo.CreateRandomAnimal());
	zoo.AddAnimal(zoo.CreateRandomAnimal());
	zoo.AddAnimal(zoo.CreateRandomAnimal());
	zoo.AddAnimal(zoo.CreateRandomAnimal());

	zoo.PerformAction();
	
}
