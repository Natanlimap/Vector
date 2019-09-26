#ifndef ARRAY_H
#define ARRAY_H


#include <cstdlib> // size_t
#include <initializer_list> // std::initializer_list
#include <algorithm> // std::copy()
namespace sc { // sequence container
  template < typename T, size_t SIZE >

    class array

    {

        private:

            T data[ SIZE ]; //!< Area de armaznamento.

        public:

            class iterator{

                private:

                    T *ptr;

                public:

                        iterator(T * pt=nullptr ) : ptr{ pt } {/*empty*/}      // it( )
                		iterator operator= (const iterator rhs){this->ptr = rhs.ptr; }
                        T& operator*(void){return ptr;}
                       	iterator operator+(size_t offset){ptr += offset; }
                        // operator=()     // it = it2;

                        // operator*()     // x = *it'

                        // operator++()    // ++it, pre-incremento

                        // operator++(int) // it++, pos-incremento.

                        // operator--()    //  --it

                        // operator--(int) // it--

                        // operator==()    // it == it2

                        // operator!=()    // it != it2

                        // operator-()     // it1 - it2

            };


            class const_iterator{

                private:

                    T *ptr;

            };


        public:

            array()

            {

                // Inicializando os dados.

                //for ( int i{0} ; i < SIZE ; ++i )

                //    data[i] = T(); // ""


                std::fill( &data[0], &data[SIZE], T() );

            }


            array( const std::initializer_list<T> & il )

            {

                /*

                // Ranged - for

                size_t i{0};

                for ( T e : il )

                {

                    if ( i > SIZE ) break

                    data[i++] = e;

                }

                */


                std::copy( il.begin(),

                           il.begin() + std::min( SIZE, il.size() ),

&data[0] );

            }



            size_t size() { return SIZE; }


            //== Element access methods

            const T& operator[]( size_t  idx ) const

            {

                return data[idx];

            }


            T& operator[]( size_t  idx )

            {

                return data[idx];

            }


            const T& at( size_t  idx ) const

            {

                if ( idx >= SIZE )

                    throw std::out_of_range("Indice invalido!");


                return data[idx];

            }


            T& at( size_t  idx )

            {

                if ( idx >= SIZE )

                    throw std::out_of_range("Indice invalido!");


                return data[idx];

            }


            //=== Element access methods

            

            // Access and retrurns the first element.

            const T& front() const

            {

                return data[0];

            }

            T& front()

            {

                return data[0];

            }

            //back()

            // TODO: implementar os back()s.

            

            void fill ( const T & value )

            {

                /*

                for ( int i{0} ; i < SIZE ; ++i )

                    data[i] = value;

                    */

                for ( T & e : data )
                    e = value;


                //std::fill( &data[0], &data[SIZE], value );

            }
            iterator begin(void){return iterator( &data[0]);}

}; // namespace sc


#endif

