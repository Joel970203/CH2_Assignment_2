#include <iostream>
#include <cstdlib>
#include <ctime>
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

class Animal 
{
public:
    virtual void makeSound() = 0;
    virtual ~Animal() {}     
};

class Dog : public Animal 
{ 
public:
    void makeSound() override 
    {
        cout << "Bow Wow!!" << endl;
    }
};

class Cat : public Animal 
{ 
public:
    void makeSound() override 
    {
        cout << "Meow~" << endl;
    }
};

class Cow : public Animal 
{
public:
    void makeSound() override 
    {
        cout << "Moo~" << endl;
    }
};

class Zoo 
{
private:
    Animal* animals[10]; 
    int IDX;           

public:
    Zoo() : IDX(0) 
    {
        for (int i = 0; i < 10; i++)
        {
            animals[i] = nullptr;
        }
    }

    void addAnimal(Animal* animal) 
    {
        if (IDX < 10) 
        {
            animals[IDX++] = animal;
        }
    }

    void performActions() 
    {
        for (int i = 0; i < IDX; i++) 
        {
            if (animals[i]) {
                animals[i]->makeSound();
            }
        }
    }

    ~Zoo() 
    {
        for (int i = 0; i < IDX; i++) 
        {
            delete animals[i]; 
        }
    }
};

Animal* createRandomAnimal() 
{
    int i = rand() % 3; 
    if (i == 0) 
    {
        return new Dog();
    }
    else if (i == 1) 
    {
        return new Cat();
    }
    else 
    {
        return new Cow();
    }
}

int main() {
    fastio();
    srand(static_cast<unsigned int>(time(0))); 

    Zoo myZoo;

    for (int i = 0; i < 10; i++) 
    {
        myZoo.addAnimal(createRandomAnimal());
    }

    myZoo.performActions();

    return 0;
}
