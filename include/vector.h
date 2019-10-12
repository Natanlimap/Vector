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
                        reference operator*(){return *ptr;} //returns the pointer`s value
                        pointer operator&(void){return ptr;}//returns the pointer`s reference
                        pointer operator->(void){return ptr;}//returns the pointer`s reference
                        iterator operator=(const iterator &rhs){this->ptr = rhs.ptr; } //returns the pointer`s value
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
                vector(const std::initializer_list<T> & il ){ //Create vector from a list
                    m_capacity = il.size();
                    m_end = il.size();
                    m_data = new T[m_capacity];
                    for(size_t i = 0; i < m_end;i++){
                        m_data[i] = *(il.begin() + i);
                    }
                }
                template< typename InputIt >
                    vector( InputIt first, InputIt last ){ //Create vector from a range
                        m_capacity = last - first ;
                        m_end = m_capacity;
                        m_data = new T[m_capacity];
                        for(size_t i = 0 ; i<m_end;i++){
                            this->m_data[i] = *(first + i);
                        }
                    }
                ~vector(){ //vector's destructor
                    delete[]m_data;
                }

                    void reserve(size_t new_cap){ //changes the vector's size
                        if(new_cap > m_capacity){

                            if(new_cap == 0){
                                new_cap = 1;
                            }
                            T *tmp = new T[new_cap];
                            for(size_t i = 0; i < new_cap; i++){
                                tmp[i] = m_data[i];
                            }
                            delete[]m_data;
                            m_data = tmp;
                            m_capacity = new_cap;
                        }
                    }
                     iterator reserve_it(size_t new_cap){ //changes the vector's size
                        if(new_cap > m_capacity){

                            if(new_cap == 0){
                                new_cap = 1;
                            }
                            T *tmp = new T[new_cap];
                            for(size_t i = 0; i < new_cap; i++){
                                tmp[i] = m_data[i];
                            }
                            delete[]m_data;
                            m_data = tmp;
                            m_capacity = new_cap;
                        }
                        return &m_data[0];
                    }

                void pop_back(){  //delete the last element
                    if(m_end>0){
                        m_end--;
                    }
                }
                void pop_front(){ //delete the frist element
                   for(size_t i = 0 ; i< m_end;i++){
                        m_data[i] = m_data[i+1];
                    }
                    m_end--;
                }

                size_t size() const{ //return the vector size
                    return m_end;
                }

                size_t capacity() const{ //return the vector capacity
                    return m_capacity;

                }

                void print(){ //print the vector
                    size_t i = 0;
                    std::cout <<"vector ->> [";
                    while(i < m_end){
                        std::cout << m_data[i] << "|";
                        i++;
                    }
                    std::cout <<"]";
                    std::cout<<std::endl;
                }

                const T& operator[]( size_t  index ) const{ //this overload the operator [] const
                    return m_data[index];
                }

                T& operator[]( size_t  index ){ //this overload the operator [] const
                    return m_data[index];
                }   

                T& at( size_t  index ) const{  //this return a data of a specific index of vector
                    if ( index >= m_end)
                        throw std::out_of_range("Indice invalido!");                
                    return m_data[index];
                }

                vector<T>& operator=( const vector<T>& other ){
                    // Precisamos verificar se o `other` "cabe" no `this`.
                    // Se não couber, precisamos realocar a memória
                    if( m_capacity < other.m_capacity )
                    {
                        reserve( other.m_capacity );
                        m_end = other.m_end;
                        //m_capacity = other.capacity;
                    }
                    for( size_t i=0 ;i < m_end ;i++){
                        m_data[i] = other.m_data[i];
                    }

                    return *this;
                }
                bool operator==(const vector<T>& other) const { //this overload the operator == 
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
         bool operator!=(const vector<T>& other) const { //this overload the operator != 
             return not ( *this == other);
            }

        const T& front() const{ //this return the data of the first element
            return m_data[0];

        }
        T& front(){ //this return the data of the first element
            return m_data[0];

        }
        const T& back() const{  //this return the data of the last element
            return m_data[m_end-1];

        }
        T& back(){ //this return the data of the last element
            return m_data[m_end-1];

        }

        bool empty(){ //this returns a boolean for the empty parameter of the vector
            return m_end == 0;
        }
        bool full(){ //this returns a boolean for the full parameter of the vector
            return m_end == m_capacity;
        }
      
        void clear(){ //this clear the vector data (I decided to match the data to default)
            for(size_t i =0; i<m_end;i++){
                m_data[i]=T();
            }
            m_end = 0;
        }
        void push_back(const T & e){ //this insert a element in the back of the vector
            if(full()){
                reserve(m_capacity*2);
            }
                this->m_data[m_end++] = e;
        }
        void push_front(const T & e){ //this insert a element in front of the vector
            if(full()){
                reserve(m_capacity*2);
            }   
            for(size_t i = m_end++;i>0;i--){
               this-> m_data[i] = this->m_data[i-1];
            }
            this->m_data[0] = e;
        }  
        void insert(iterator position, const T& val){
            size_t distance = position - m_data;
            iterator first;
            if(full()){
                first = reserve_it(m_capacity*2);
                position = first + distance;
            }

            for(size_t i = m_end++; i>distance; i--){
                m_data[i] = m_data[i-1];
            }
            m_data[distance] = val; 
        }
        void insert(iterator pos, const std::initializer_list<T> & il){
            iterator first;
            size_t list_distance = il.end() - il.begin();
            size_t distance, count;
            distance = pos - m_data;
            if(full()){
                first = reserve_it((m_capacity+list_distance)*2);
                pos = first + distance;
            }  
            distance = pos - m_data;
            m_end += list_distance;
            for(size_t i = m_end ; i>distance;i--){
                m_data[i] = m_data[i - list_distance];
            }

            count = 0;
            for(size_t i = distance; i < distance + list_distance; i++){
                m_data[i] = *(il.begin() + count++);
                
            }
        }
        void insert(iterator pos, iterator first, iterator last){
            size_t initial = pos - m_data;
            size_t distance = &m_data[m_end] - pos;
            size_t tam = last - first;
            m_end += tam;

            for(size_t i = m_end ; i>initial;i--){
                m_data[i] = m_data[i - tam];
            }
            size_t count = 0;
             for(size_t i = initial; i < initial + tam; i++){
                m_data[i] = *(first + count++);
                
            }
        }
        



         void erase(iterator position){
            size_t distance = position - m_data;
            for(size_t i = distance; i<m_end; i++){
                m_data[i] = m_data[i+1];
            }
            --m_end;
        }
         void erase(iterator first, iterator last){
            size_t distance;
            distance = first - m_data;
            for(size_t i = distance ; i < m_end; i++){
                m_data[i] = m_data[i + (last - first+1)];
            }
            m_end -= last-first+1;
        }
        void assign( size_t count, const T & value ){
            if ( count >= m_capacity )
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
       
        iterator begin(){return &m_data[0];}
        iterator end(){return &m_data[m_end];}
        const_iterator cbegin()const{return &m_data[0];}
        const_iterator cend()const{return &m_data[m_end];}

    };
}
