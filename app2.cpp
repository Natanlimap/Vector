#include <iostream>
#include <cassert>

#include "vector.h"

#include <iostream>


int main () {
    sc::vector<int> C{1,2,3,4,5, 99, 22, 32, 76, 100,};
    sc::vector<int> D{9,2,2,4,5, 0, 22, 0, 76, 0, 1 ,2, 3,};
    sc::vector<int> B;
	sc::vector<int>::iterator it = D.begin();
	sc::vector<int>::iterator it2 = (D.end());
    sc::vector<int> A(it, it2);
	if(B != C){
		std::cout << *it;
	}
	// D.erase(it);
	// A.print();
	// B.print();
	// C.print();
	// D.print();
    return 0;
}