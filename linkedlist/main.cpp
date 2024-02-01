#include <iostream>
#include "linkedlist.h"
int main()
{
    linkedlist l;
    l.add_node(1);
    l.add_node(2);
    l.add_node(3);
    std::cout << l[0] << " " << l[1] << " " << l[2] << "\n";
    l.delete_node(2);
    std::cout << l[0] << " " << l[1] << "\n";
    l.insert_node(1, 114);
    std::cout << l[0] << " " << l[1] << " " << l[2] << "\n";
    return 0;
}