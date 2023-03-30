#include <iostream>
#include <string>

class Persona 
{
    protected:
        std::string eyesColor = "Chocolate";

    public:
        std::string name;
        int age;

        //Una forma adecuada de generar el constructor con el apuntador this
        Persona( std::string name, int age)
        {
            this->name = name;
            this->age = age;
        }

        // No podemos tener el mismo name ya que genera ambiiguage ( lo mejor seria usar this)
        // Persona( std::string _name, int _age)
        // {
        //     name = _name;
        //     age = _age;
        // }

        //Otra opcion para el constructor
        // Persona( std::string _name, int _age) : name(_name), age(_age) {}

        ~Persona()
        {
            std::cout << "Invocacion al destructor" << '\n';
            // Deben limpiar la memoria dinamica la estatica se mantiene (se modifica solo al escribir el codigo). 
        }
        void setEyesColor( std::string color )
        {
            this->eyesColor = color;
        }
        std::string getEyesColor()
        {
            return eyesColor;
        }

    
        void saludar()
        {
            std::cout << "Hola mi name es " << this->name << ", mi color de ojos es " << this->eyesColor << '\n';
        }


        //En ocaciones vamos a querer retornar la instancia al ejecutar un metodo. con el fin de concatenar metodos.
        Persona &setName( std::string name )
        {
            this->name = name;
            return *this;
        }

};


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