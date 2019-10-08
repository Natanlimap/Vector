#include <iostream>
#include <cassert>

#include "vector.h"

#include <iostream>


int main () {
    sc::vector<int> C{1,2,3,4,5, 99, 22, 32, 76, 100};
    sc::vector<int> B(C);
	sc::vector<int>::iterator it = C.begin();
	sc::vector<int>::iterator it2 = (C.end());
	if(B != C){
		std::cout << "teste";
	}
	B.print();
	C.print();
	std::cout<<*it;
    return 0;
}