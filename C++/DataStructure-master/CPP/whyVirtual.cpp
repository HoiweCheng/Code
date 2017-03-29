#include<iostream>
using namespace std;

//example from stackoverflow
//override: early binding while compiling
//virtual: dynamic (later) binding while running
class Animal
{
    public:
        virtual void eat()
        {
            cout << "eat food" << endl;
        }
};

class Cat: public Animal
{
    public:
        void eat()
        {
            cout << "eat rat" << endl;
        }
};

void func(Animal &obj)
{
    obj.eat();
}

int main()
{
    Animal animal;
    Cat cat;
    func(animal);
    func(cat);
    return 0;
}

