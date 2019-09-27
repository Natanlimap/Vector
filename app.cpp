#include <iostream>
#include <cassert>

#include "vector.h"

template <typename T, size_t SIZE >
std::ostream & operator<<( std::ostream & os, const sc::vector <T, SIZE> & a ){
	
	os<< "[|";
	for (size_t i{0u}; i < SIZE ; i++){
		os << a[i] << " |";
	}
	os << "]";
	return os;
}
}

int main(void){

   
	sc::vector < int, 10 > A{1,2,3,4,5, 99, 22, 32, 76, 34};
	sc::vector < int, 10 > B;
	sc::vector < int, 10 > C(A); //construtor copia

	//B = A; //sobrecarga
	try{
		A.at(10) = -3;
	}
	catch(std::out_of_range e ){
		std::cout <<  "exceção caurada! MSG = " << e.what() << std::endl;
	}

	std::cout << ">>> Vetor A" << A << std::endl;
	std::cout << ">>> Vetor B" << B << std::endl;
	std::cout << ">>> Vetor C" << C << std::endl;
	//A.resize(15);
	//std::cout << ">>> Vetor A" << A << std::endl;
	return 0;
}