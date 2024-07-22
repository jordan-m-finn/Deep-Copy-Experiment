// Array class definition with overloaded operators.
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Comment 1:
//
template<typename T>
class Array
{
   friend std::ostream &operator<<( std::ostream &, const Array & );
   friend std::istream &operator>>( std::istream &, Array & );

public:
  explicit Array( size_t = 10 ); // default constructor
   Array( const Array & ); // copy constructor
   ~Array(); // destructor
   size_t getSize() const; // return size

   const Array &operator=( const Array & ); // assignment operator
   bool operator==( const Array & ) const; // equality operator

   // inequality operator; returns opposite of == operator
   bool operator!=( const Array &right ) const  
   { 
      return ! ( *this == right ); // invokes Array::operator==
   } // end function operator!=
   
   // subscript operator for non-const objects returns modifiable lvalue
   
   // Comment 3:
   //
   T &operator[](size_t);              
   // subscript operator for const objects returns rvalue
   const T &operator[](size_t) const;  
private:
   size_t size; // pointer-based array size
   // Comment 4:
   //
   T *ptr; // pointer to first element of pointer-based array
}; // end class Array

#endif

// ---------------- I M P L E M E N T A T I O N -----------------------------//


