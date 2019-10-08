#include <iostream>
#include <cstdlib> // size_t
#include <initializer_list> // std::initializer_list
#include <algorithm> 


namespace sc{ //sequence container
	template <typename T>
	class vector{

	private: 
		size_t m_end;
        size_t m_capacity;
        T* m_data;

	public:
         //ITERATORS
        class iterator{
                private:
                    T *ptr;
                public:
                    iterator(T * pt=nullptr ) : ptr{ pt }{}      // it( )
                    T& operator*(void){return *ptr;}
                    iterator operator= (const iterator rhs){this->ptr = rhs.ptr; }
                    iterator operator+(size_t offset){ptr += offset; }
                    iterator operator++(){++ptr; }
                    iterator operator++(int){ptr++; }
                    iterator operator--(){--ptr; }
                    iterator operator--(int){ptr--; }
                    iterator friend operator+(int n, iterator it){return it+n;}
                    iterator friend operator+(iterator it, int n){return n + it;}
                    iterator friend operator-(int n, iterator it){return it-n;}
                    iterator friend operator-(iterator it, int n){return n-it;}

                  
                    bool operator==(const iterator rhs){return *this->ptr == *rhs.ptr;}
                    bool operator!=(const iterator rhs){return *this->ptr != *rhs.ptr;}
                    bool operator>(const iterator rhs){return this->ptr > rhs.ptr;}
          

     };
     class const_iterator{
        private:
        T *ptr;
        public: 
         const_iterator cbegin(void) const{return iterator(&m_data[0]);}
         const_iterator cend(void) const{return iterator(&m_data[m_end]);}
     };

        public:

        vector(size_t cap=1){ //constructor normal
        	 m_capacity = 0;
   			 m_end = 0;
   			 m_data = new T[m_capacity];

        }
        ~vector(){
        	delete[]m_data;
        }
        vector(vector<T>const& m_old){    //constructor copy
            m_capacity = m_old.capacity();
            m_end = m_old.size();
            m_data = new T[m_capacity];
            for(size_t i = 0; i < m_capacity; i++){
                m_data[i] = m_old[i]; 
            }
        }
         vector( const std::initializer_list<T> & il ){ //inicializador de informações
            m_capacity = il.size();
            m_end = il.size();
            m_data = new T[m_capacity];
            for(size_t i = 0; i < m_end;i++){
                m_data[i] = *(il.begin() + i);
            }
        }
        // vector(iterator first, iterator last){
        //     m_capacity = std::distance(first, last);
        //     m_end = m_capacity;
        //     m_data = new T[m_capacity];
        //     for(size_t i = 0 ; i<m_end;i++){
        //         this->m_data[i] = first + i;
        //     }
        // }

        void reserve(size_t new_cap){
            if(new_cap == 0){
                new_cap = 1;
            }
		    T *tmp = new T[new_cap];
		    for(size_t i = 0; i < new_cap; i++){
		    	if(i < m_capacity){
		    		tmp[i] = m_data[i];
		    	}else{
		    		tmp[i] = T();
		    	}
		    }
		    delete[]m_data;
		    m_data = tmp;
		     if (!tmp)
		         throw std::bad_alloc();
             if(m_capacity > new_cap){
                m_end = new_cap;
             }
		    m_capacity = new_cap;
		}
   
        void pop_back(){
            if(m_end>0){
                --m_end;
            }
        }
        void pop_front(){
            for(size_t i = 0 ; i< m_end;i++){
                m_data[i] = m_data[i+1];
            }
            m_end--;
        }

        size_t size() const{
            return m_end;
        }
        size_t capacity() const{
            return m_capacity;

        }
        
        void print(){
        	size_t i = 0;
            std::cout <<"vector ->> [";
        	while(i < m_end){
        		std::cout << m_data[i] << "|";
        		i++;
        	}
            std::cout <<"]";
        	std::cout<<std::endl;
        }

		const T& operator[]( size_t  index ) const{
             return m_data[index];
        }

        T& operator[]( size_t  index ){
             return m_data[index];
        }

        // const T& at( size_t  index ) const{
        //         if ( index >= m_end)
        //             throw std::out_of_range("Indice invalido!");    
        //         return m_data[index];
        // }

        T& at( size_t  index ) const{
                if ( index >= m_end)
                   throw std::out_of_range("Indice invalido!");                
                return m_data[index];
        }
        bool operator==(const vector<T> idx ) const{
            for(size_t i = 0; i < m_end;i++){
                if(m_data[i]!= idx[i]){
                    return false;
                }
            }
                return true;

        }
         
        const bool operator!=(const vector<T> idx ) const{
             for(size_t i = 0; i < m_end;i++){
                if(m_data[i]!= idx[i]){
                    return true;
                }
             }
                return false;

        }
        bool operator!=(const vector <T> idx ){
            for(size_t i = 0; i < m_end;i++){
                if(m_data[i]!= idx[i]){
                    return true;
                }
            }
                return false;
        }

        const T& front() const{
            return m_data[0];

        }
        T& front(){
            return m_data[0];

        }
        const T& back() const{
            return m_data[m_end];

        }
        T& back(){
            return m_data[m_end];

        }

        bool empty(){
        	return m_end == 0;
        }
        bool full(){
        	return m_end == m_capacity;
        }
        // T vector<T>::pop(){
        // 	return *(m_data + --m_end);
        // }
        void clear(){
            for(size_t i =0; i<m_end;i++){
                m_data[i]=T();
            }
            m_end = 0;
        }
        void push_back(const T & e){
        	if(full()){
        		reserve(m_capacity*2);
        	}
        		this->m_data[m_end++] = e;
        }
        void push_front(const T & e){
            if(full()){
                reserve(m_capacity*2);
            }   
            for(size_t i = ++m_end;i>0;i--){
               this-> m_data[i] = this->m_data[i-1];
            }
            this->m_data[0] = e;
        }  
        void insert (iterator position, const T& val){
           if(full()){
                reserve(m_capacity*2);
            }
            T *last;
            last = &m_data[m_end+1];
            while(position>last){
                *last = *(last-1);
                last--;
             }
            *position = val;

        }
        void assign( size_t count, const T & value ){
            reserve(count);
            for(size_t i = 0; i < count ; i++){
                this-> m_data[i] = value;
            }
        }
        void shrink_to_fit(){
            if(full()){

            }
            else{
                reserve(m_end);
            }
        }
        void eraser(){

        }
       
        iterator begin(){return iterator( &m_data[0]);}
        iterator end(){return iterator( &m_data[m_end]);}
        const_iterator cbegin() const{return iterator(&m_data[0]);}
        const_iterator cend() const{return iterator(&m_data[m_end]);}

    };
}