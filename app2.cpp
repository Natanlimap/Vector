#include <iostream>
#include <cassert>

#include "vector2.h"

#include <iostream>


int main () {
    sc::Vector<int> arr;
    sc::Vector<int> B(arr);
    sc::Vector<int> C{1,2,3,4,5, 99, 22, 32, 76, 100};
    for(int i = 0; i<10;i++){
        arr.push_back(i);
    }
	sc::Vector<int>::iterator it = C.begin();
	sc::Vector<int>::iterator it2 = (C.end());
	*it = 10;
	C.print();
	*it2 = *(it2 - 1);
	*it2 = *it;
	if(*it == *it2){
		std::cout<<"oi";
	}
    return 0;
}