#include <iostream>
#include <cassert>

#include "../include/vector.h"

#include <iostream>


int main () {
    sc::vector<int> C{1,2,3,4,3};
    sc::vector<int>::iterator it = C.end();
    C.insert(it, 2);
    C.print();
    return 0;
}
