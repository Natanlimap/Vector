#include <iostream>
#include <cassert>

#include "vector2.h"

#include <iostream>

int main () {
    sc::Vector<int> arr;
    for(int i = 0; i<10;i++){
        arr.push_back(i);
    }
    arr.print();
//    std::cout << "Popping.. " << arr.pop() << "\n";
  //  std::cout << "Setting pos 2 to 99 ... \n";
    arr.push_back(5);
    //arr.set(2, 99999);
    arr.print();
    if(arr.full()){
        std::cout<<"cheio";
    }
    return 0;
}