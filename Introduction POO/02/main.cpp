#include <iostream>
#include <string>
#include "Persona.hpp"


//Es posible separa el codigo en varios modulos
int main()
{
    Persona p = Persona("Diana", 23);
    p.saludar(); 

    Persona *p2 = new Persona("Martin", 33);
    // p2->name = "Juan";
    p2->saludar(); 


    std::cout << p2->name << '\n'; 
    // std::cout << p2->eyesColor << '\n'; // Error
    std::cout << p2->getEyesColor() << '\n';

    p2->setName("D4ndres").saludar();

    return 0;
}