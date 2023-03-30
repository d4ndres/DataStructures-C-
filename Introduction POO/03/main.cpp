#include <iostream>
#include <string>
#include "Animal.hpp"

int main()
{
    Carnivoro *tigre = new Carnivoro();
    tigre->devorar();
    
    Hervivoro *vaca = new Hervivoro();
    vaca->pastar();
    
    Omnivoro *cuervo = new Omnivoro();
    cuervo->devorar();
    cuervo->pastar();
    
    std::cout << tigre->getNumberInstance();


    return 0;
} 