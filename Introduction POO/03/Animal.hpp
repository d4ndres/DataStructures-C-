#include <iostream>
#include <string>

class Animal 
{
    protected:
        static int numberInstance;
        std::string alimento = "...";
    
    public:
        Animal();
        ~Animal();
        void comer();
        int getNumberInstance();

};

int Animal::numberInstance = 0;

Animal::Animal()
{
    std::cout << "Nuevo animal" << '\n';
    this->numberInstance++;
}

Animal::~Animal()
{
    std::cout << "Animal destruio" << '\n';
    this->numberInstance--;
}
void Animal::comer()
{
    std::cout << "El animal esta comiendo " << this->alimento << " fritos" << '\n';
}

int Animal::getNumberInstance()
{
    return this->numberInstance;
}



// Creacion de clase hervivoro

class Hervivoro : public Animal 
{
    public:
        Hervivoro();
        void pastar();
};

Hervivoro::Hervivoro() : Animal()
{
    this->alimento = "Plantas";
}

void Hervivoro::pastar()
{
    std::cout << "Salio a pastar" << '\n';
}




// Creacion de clase Carnivoro

class Carnivoro : public Animal 
{
    public:
        Carnivoro();
        void devorar();
};

Carnivoro::Carnivoro() : Animal()
{
    this->alimento = "Cerdo";
}

void Carnivoro::devorar()
{
    std::cout << "Salio a devorar" << '\n';
}



// Aunque se puede realizar herencia multiple es preferible heredar de solo una clase padre
// Creacion de clase Omnivoro

class Omnivoro : public Hervivoro, public Carnivoro 
{
    public:
        Omnivoro();
};

Omnivoro::Omnivoro() : Hervivoro(), Carnivoro() {}