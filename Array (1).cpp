// Array class member- and friend-function definitions.
#include <iostream>
#include <iomanip>
#include <stdexcept> 

#include "Array (1).h" // Array class definition
using namespace std;

// default constructor for class Array (default size 10)
// Comment 5:
// 
template <typename T>
Array<T>::Array(size_t arraySize)
	: size(arraySize > 0 ? arraySize :
		throw invalid_argument("Array size must be greater than 0"))
{
	ptr = new T[arraySize];
	cout << "INSIDE (int) CONSTRUCTOR...\n\n";

	for (size_t i = 0; i < size; ++i)
		ptr[i] = T(); // set pointer-based array element
} // end Array default constructor

// copy constructor for class Array;
// must receive a reference to an Array
// Comment 6:
// 
template <typename T>
Array<T>::Array(const Array& arrayToCopy) : size(arrayToCopy.size)
{
	ptr = new T[size];
	cout << "INSIDE COPY CONSTRUCTOR...\n\n";

	for (size_t i = 0; i < size; ++i)
		ptr[i] = arrayToCopy.ptr[i]; // copy into object
} // end Array copy constructor

// destructor for class Array
// Comment 7:
// 
template <typename T>
Array<T>::~Array()
{
	cout << "INSIDE DESTRUCTOR...\n\n";
	delete[] ptr; // release pointer-based array space
} // end destructor

// return number of elements of Array
// Comment 8:
// 
template <typename T>
size_t Array<T>::getSize() const
{
	return size; // number of elements in Array
} // end function getSize

// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
// Comment 9:
//
template <typename T>
const Array<T>& Array<T>::operator=(const Array& right)
{

	cout << "INSIDE ASSIGNMENT OPERATOR...\n\n";

	if (this != &right) {
		delete[] ptr;
		size = right.size;
		ptr = new T[size];
		for (size_t i = 0; i < size; ++i)
			ptr[i] = right.ptr[i];
	}

	else
		cout << "SELF ASSIGNMENT WAS ATTEMPTED!\n\n";

	return *this; // enables x = y = z, for example
} // end function operator=

// determine if two Arrays are equal and
// return true, otherwise return false
// Comment 10:
//
template <typename T>
bool Array<T>::operator==(const Array& right) const
{
	if (size != right.size)
		return false; // arrays of different number of elements

	for (size_t i = 0; i < size; ++i)
		if (ptr[i] != right.ptr[i])
			return false; // Array contents are not equal

	return true; // Arrays are equal
} // end function operator==

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
// Comment 11:
// 
template <typename T>
T &Array<T>::operator[](size_t subscript)
{

	cout << "INSIDE OF NON-CONST OPERATOR[]\n\n";

	// check for subscript out-of-range error
	if (subscript < 0 || subscript >= size)
		throw out_of_range("Subscript out of range");

	return ptr[subscript]; // reference return
} // end function operator[]

// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
// Comment 12:
//
template <typename T>
const T &Array<T>::operator[](size_t subscript) const
{

	cout << "INSIDE OF CONST OPERATOR[]\n\n";

	// check for subscript out-of-range error
	if (subscript < 0 || subscript >= size)
		throw out_of_range("Subscript out of range");

	return ptr[subscript]; // returns copy of this element
} // end function operator[]

// overloaded input operator for class Array;
// inputs values for entire Array
// Comment 13:
//
template <typename T>
istream& operator>>(istream& input, Array<T>& a)
{
	for (size_t i = 0; i < a.size; ++i)
		input >> a.ptr[i];

	return input; // enables cin >> x >> y;
} // end function 

// overloaded output operator for class Array 
// Comment 14:
//
template <typename T>
ostream& operator<<(ostream& output, const Array<T>& a)
{
	// output private ptr-based array 
	for (size_t i = 0; i < a.size; ++i)
	{
		output << setw(12) << a.ptr[i];

		if ((i + 1) % 4 == 0) // 4 numbers per row of output
			output << endl;
	} // end for

	if (a.size % 4 != 0) // end last line of output
		output << endl;

	return output; // enables cout << x << y;
} // end function operator<<
