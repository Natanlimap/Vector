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
   			// m_data = (T*)malloc(m_capacity * sizeof(*m_data));
   			 m_data = new T [cap];
  			 if (!m_data)
				throw std::bad_alloc();
        }
        ~Vector(){
        	free(m_data);
        }

        void resize() {
		    size_t capacity = m_capacity*2;
		    T *tmp = (T*)realloc(m_data, capacity * sizeof(*m_data));
		    // if (!tmp)
		    //     throw std::bad_alloc();
		    m_data = tmp;
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
        		resize();
        	}
        		this->m_data[m_end++] = e;
        }
         const T& front() const

            {

                return data[0];

            }

            T& front()

            {

                return data[0];

            }
	};
}