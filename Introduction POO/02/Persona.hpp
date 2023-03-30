#include <iostream>
#include <string>

class Persona 
{
    protected:
        std::string eyesColor = "Chocolate";

    public:
        static int numberInstance; 
        std::string name;
        int age;

        Persona( std::string name, int age);

        ~Persona();

        void setEyesColor( std::string color );

        std::string getEyesColor();
    
        void saludar();

        Persona &setName( std::string name );

};

int Persona::numberInstance = 0;

Persona::Persona( std::string name, int age)
{
    this->name = name;
    this->age = age;

    //Util manejar los datos estaticos para comunicar instancias. Como tener una PK en una DB.
    this->numberInstance++;
    std::cout << "Instancia " << this->numberInstance << " Persona creada" << '\n';
}

Persona::~Persona()
{
    std::cout << "Invocacion al destructor" << '\n';
}

void Persona::setEyesColor( std::string color )
{
    this->eyesColor = color;
}

std::string Persona::getEyesColor()
{
    return eyesColor;
}

void Persona::saludar()
{
    std::cout << "Hola mi name es " << this->name << ", mi color de ojos es " << this->eyesColor << '\n';
}

Persona &Persona::setName( std::string name )
{
    this->name = name;
    return *this;
}
