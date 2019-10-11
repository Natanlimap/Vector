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
            typedef std::ptrdiff_t difference_type; //!< Difference type used to calculated distance between iterators.
            typedef T value_type;           //!< Value type the iterator points to.
            typedef T* pointer;             //!< Pointer to the value type.
            typedef T& reference;           //!< Reference to the value type.
            typedef const T& const_reference;           //!< Reference to the value type.
            typedef std::bidirectional_iterator_tag iterator_category; //!< Iterator category.
                    iterator(T * pt=nullptr) : ptr{ pt }{}      // it( )
                    reference operator*(){return *ptr;}
                    pointer operator&(void){return ptr;}
                    pointer operator->(void){return ptr;}
                    iterator operator=(const iterator &rhs){this->ptr = rhs.ptr; }
                    iterator operator=(T& a){*this->ptr = a; }
                    iterator operator+(size_t offset){return this->ptr = this->ptr + offset; }
                    iterator operator-(size_t offset){ptr = ptr - offset; }
                    size_t operator-(const iterator& lhs){return this->ptr - lhs.ptr;}
                    iterator& operator++() { ++ptr; return *this;}
                    iterator operator++(int){return ptr++;}
                    iterator& operator--() { --ptr; return *this;}
                    iterator operator--(int){return ptr--;}

                    friend size_t operator-(T *a, const iterator &lhs){return (a - lhs.ptr);} //distance

                    bool operator==(const iterator& rhs) const {return *this->ptr == *rhs.ptr;}
                    bool operator!=(const iterator& rhs) const {return *this->ptr != *rhs.ptr;}
                    bool operator>(const iterator &rhs) const {return this->ptr > rhs.ptr;}
                    bool operator<(const iterator &rhs) const {return this->ptr < rhs.ptr;}
                    bool operator<=(const iterator &rhs) const {return this->ptr <= rhs.ptr;}

     };

    public:

     class const_iterator{
        private:
        const T *ptr;
        public: 
          
            typedef std::ptrdiff_t difference_type; //!< Difference type used to calculated distance between iterators.
            typedef T value_type;           //!< Value type the iterator points to.
            typedef T* pointer;             //!< Pointer to the value type.
            typedef T& reference;           //!< Reference to the value type.
            typedef const T& const_reference;           //!< Reference to the value type.
            typedef std::bidirectional_iterator_tag iterator_category; //!< Iterator category.
                    const T& operator*(void){return *ptr;}
                    const T*& operator&(void){return ptr;}
                    const T*& operator->(void){return ptr;}
                    const iterator operator= (const iterator rhs){this->ptr = rhs.ptr; }
                    const iterator operator+(size_t offset){return ptr = ptr + offset; }
                    const iterator operator-(size_t offset){ptr -= offset; }
                    const iterator operator-(const iterator &rhs){this->ptr = this->ptr - rhs.ptr; }
                    const iterator& operator++() { ++ptr; return *this;}
                    const iterator operator++(int){return ptr++;}
                    const iterator& operator--() { --ptr; return *this;}
                    const iterator operator--(int){return ptr--;}

                  
                    bool operator==(const iterator& other) const{return *this->ptr == *other.ptr;}
                    bool operator!=(const iterator& other) const{return *this->ptr != *other.ptr;}
                    bool operator>(const iterator rhs) const {return this->ptr > rhs.ptr;}
                    bool operator<(const iterator rhs) const {return this->ptr < rhs.ptr;}
          
      
     };

        public:

        vector(){ //constructor normal
             m_capacity = 0;
             m_end = 0;
             m_data = new T[m_capacity];

        }
        vector(vector<T>const& m_old){    //constructor copy
            m_capacity = m_old.capacity();
            m_end = m_old.size();
            m_data = new T[m_capacity];
            for(size_t i = 0; i < m_capacity; i++){
                m_data[i] = m_old[i]; 
            }
        }
         vector(size_t a){    
            m_capacity = a;
            m_end = 0;
            m_data = new T[m_capacity];
            for(size_t i = 0; i<m_end;i++){
                m_data[i] = T();
            }
        }
         vector(const std::initializer_list<T> & il ){ //inicializador de informações
            m_capacity = il.size();
            m_end = il.size();
            m_data = new T[m_capacity];
            for(size_t i = 0; i < m_end;i++){
                m_data[i] = *(il.begin() + i);
            }
        }
        template< typename InputIt >
        vector( InputIt first, InputIt last ){
            m_capacity = last - first ;
            m_end = m_capacity;
            m_data = new T[m_capacity];
            for(size_t i = 0 ; i<m_end;i++){
                this->m_data[i] = *(first + i);
            }
        }
        ~vector(){
            delete[]m_data;
        }
        void reserve(size_t new_cap){
            if(m_capacity == 0){
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
             }else{
                m_capacity = new_cap;
             }
        }
   
        void pop_back(){
            if(m_end>0){
                m_end--;
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

        T& at( size_t  index ) const{
                if ( index >= m_end)
                   throw std::out_of_range("Indice invalido!");                
                return m_data[index];
        }
      
        bool operator==(const vector<T>& other) const {
                if(m_end == other.size()){
                    for(size_t i = 0; i < m_end; i++){
                        if(m_data[i] != other[i]){
                            return false;
                        }
                    }
                    return true;
                }
                else{
                    return false;
                }
            }
         bool operator!=(const vector<T>& other) const {
                if(m_end == other.size()){
                    for(size_t i = 0; i < m_end; i++){
                        if(m_data[i] != other[i]){
                            return true;
                        }
                    }
                    return false;
                }
                else{
                    return false;
                }
            }

        const T& front() const{
            return m_data[0];

        }
        T& front(){
            return m_data[0];

        }
        const T& back() const{
            return m_data[m_end-1];

        }
        T& back(){
            return m_data[m_end-1];

        }

        bool empty(){
            return m_end == 0;
        }
        bool full(){
            return m_end == m_capacity;
        }
      
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
        void insert (iterator &position, const T& val){
           if(full()){
                reserve(m_capacity*2);
            }
            *position = 2;
            std::cout<<*position<<std::endl; 
        }
        void assign( size_t count, const T & value ){
            reserve(count);
            for(size_t i = 0; i < count ; i++){
                this-> m_data[i] = value;
            }
            m_end = count;

        }
        void shrink_to_fit(){
            m_capacity = m_end;
            reserve(m_end);

        }
       
        void erase(iterator it){
            T *first;
            T *last;
            first = &it;
            last = &m_data[m_end-1];
            while(first<last){
                 *first = *(first+1);
                first++;
            }
        }
        iterator begin(){return &m_data[0];}
        iterator end(){return &m_data[m_end-1];}
        const_iterator cbegin()const{return &m_data[0];}
        const_iterator cend()const{return &m_data[m_end];}

    };
}
