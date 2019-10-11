#include <iostream>
#include <cassert>

#include "../include/vector.h"

#include <iostream>


int main () {
    sc::vector<int> C{1,2};
    sc::vector<int>::iterator it = C.begin();
    C.print();
    C.insert(it, 4);
    C.print();

    return 0;
}
