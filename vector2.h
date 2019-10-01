#include <iostream>
#include <cstdlib> // size_t
#include <initializer_list> // std::initializer_list
#include <algorithm> 

namespace sc{ //sequence container
	template <typename T>
	class Vector{

	private: 
		size_t m_end;
        size_t m_capacity;
        T* m_data;
	public:
		
        Vector(size_t cap=1){
        	 m_capacity = cap;
   			 m_end = 0;
   			 m_data = new T [cap];
  			 if (!m_data)
				throw std::bad_alloc();
        }
        ~Vector(){
        	delete[]m_data;
        }

        void reserve(size_t capacity){
		    T *tmp = new T[capacity];
		    for(size_t i = 0; i < capacity; i++){
		    	if(i < m_capacity){
		    		tmp[i] = m_data[i];
		    	}else{
		    		tmp[i] = T();
		    	}
		    }
		    delete[]m_data;
		    m_data = tmp;
		    // if (!tmp)
		    //     throw std::bad_alloc();
		    
		    m_capacity = capacity;
		}

        void set(size_t index, T value){
        	while(index >= m_end){
        		this -> push(0);
        		*(m_data = m_end++) = value;
        	}
        }
   
        T pop();
        T get(size_t index);

        size_t size();
        size_t capacity();
        
        void print(){
        	size_t i = 0;
        	while(i < m_end){
        		std::cout <<"Vector"<< "[" << i << "]" << "=" << m_data[i] << std::endl;
        		i++;
        	}
        	std::cout<<std::endl;
        }
		int is_empty();

		const T& operator[]( size_t  idx ) const{
             return m_data[idx];
        }

        T& operator[]( size_t  idx ){
             return m_data[idx];
        }

        bool empty(){
        	return m_end == 0;
        }
        bool full(){
        	return m_end == m_capacity;
        }
        // T Vector<T>::pop(){
        // 	return *(m_data + --m_end);
        // }
        void push_back(const T & e){
        	if(full()){
        		reserve(m_capacity*2);
        	}
        		this->m_data[m_end++] = e;
        }
     

	};
}