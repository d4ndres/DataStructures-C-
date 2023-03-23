#pragma once 
#include <cstring>

class ArrayList
{
private:
    int m_size; // espacios totales.
    int m_capacity; // espacios disponibles

    int *m_elements; //optimizacion de memoria. sera capas de acceder a todos los elementos.

public:
    ArrayList();

    // Eliminamos los contructores para limpiar memoria
    ArrayList( const ArrayList &other ) = delete; 
    ArrayList operator = ( const ArrayList &other ) = delete;

    ~ArrayList();
    
    // Regresa elemento apartir indice.
    int at( int index ) const; 

    // Agrega elemento.
    void add( int element);

    // Remueve elemento.
    void remove( int element);

    // Remueve elemento apartir del indice.
    void removeAt( int index);

    // Contiene elementos
    bool contains( int element) const;

    // regresa el tamaño del arrayList
    unsigned size() const;

    //El const al final lo indicamos para que ele programa entienda que no cambiara la estructura interna.

    void show() const;

};

//Constructor
ArrayList::ArrayList()
    :m_size{0}, m_capacity{5}, m_elements{nullptr}
{
    m_elements = new int[m_capacity]; //inicializacion del array
}

//Destructor
ArrayList::~ArrayList()
{
    if( m_elements != nullptr)
    {
        delete[] m_elements;
        m_elements = nullptr;
    }
}

int ArrayList::at( int index) const
{
    if( index >= m_size){
        return -1;
    }
    return m_elements[index];
}

void ArrayList::add( int element)
{
    if(m_size == m_capacity)
    {
        m_capacity += 5;
        int *tempArray = new int[m_capacity];
        std::memcpy(tempArray, m_elements, sizeof(int) * m_size);
        delete[] m_elements;
        m_elements = tempArray;
    }
    m_elements[m_size] = element;
    ++m_size;
    
}

void ArrayList::remove(int element)
{
    for( int i = 0; i < m_size; i++)
    {
        if( m_elements[i] == element ){
            std::memcpy( m_elements + i, m_elements + i + 1, sizeof(int) * (m_size - i - 1) );
            --m_size;
            --i;
        }
    }
}

void ArrayList::removeAt( int index)
{
    if( index >= m_size){
        return;
    }
    std::memcpy( m_elements + index, m_elements + index + 1, sizeof(int) * (m_size - index - 1) );
}

bool ArrayList::contains( int element) const
{
    for( int i = 0; i < m_size; i++)
    {
        if( m_elements[i] == element){
            return true;
        }
    }
    return false;
}

unsigned ArrayList::size() const
{
    return m_size;
}

void ArrayList::show() const
{
    std::cout << "[";
    for( int i = 0; i < m_size; i++){
        if( !i ) {
            std::cout << at(i);
            continue;
        }
        std::cout << "," << i;
    }
    std::cout << "]\n";
}