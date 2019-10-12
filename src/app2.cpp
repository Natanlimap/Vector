#include <iostream>
#include <cassert>

#include "../include/vector.h"

#include <iostream>


int main () {
    sc::vector<int> C{1,2,3,4,5};
    sc::vector<int> D{9,10, 11,4};
    sc::vector<int> B;
    D.insert(C.begin()+1, {5,5});
    D.print();
    return 0;
}
