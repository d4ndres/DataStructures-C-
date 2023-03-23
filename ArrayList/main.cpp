#include <iostream>
#include "arraylist.hpp"

int main() {
    std::cout<<"Hello data structures\n";

    ArrayList list;
    std:: cout << "size:" << list.size() << "\n";
    list.add(7);
    list.add(2);
    list.add(3);
    std::cout << "size:" << list.size() << "\n";
    list.add(7);
    list.add(1);
    list.add(3);
    std::cout << "size:" << list.size() << "\n";
    list.show();
    list.remove(7);
    list.show();
    

    return 0;
}