#include <iostream>
#include <cassert>

#include "../include/vector.h"

#include <iostream>


int main () {
    sc::vector<int> C{5, 6};
    sc::vector<int> D{1,2, 3,4, 5};
    sc::vector<int> B;
     D.print();
    D.insert(D.begin(),C.begin(), C.begin()+1);
    D.print();
    return 0;
}
