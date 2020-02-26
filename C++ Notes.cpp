C++ Notes

// DATE 01/22/2019
compile with g++:
g++ <filename>.cpp
./<filename>.out


// don't need to specify a return statement, auto returns 0


// smallest program you can write in C++
int main(){}

// to properly cast
cast-name<type>(expression)
// maybe like
double x = 2.0;
int y = cast-name<int>(x);


// complier deduces the data type from assignment -> auto-fills generic
auto i = 0;

// 0 value is false. Any other value pos or neg is true


// when code is handled by complier then everything
// is figured out before run-time
// has no impact on the run-time speed.

// DATE 01/29/2020

// while
while(expression) {
	statements;
}


// goto statements
// goto make it harder to follow program flow and debug
goto gotoLbl;

gotoLbl:
...


// I/O

// namespace
// A named scope
// Similar to package in Java

// Using declarations
using namespace 'namespace'
-Exposes all the names from 'namespace'
-Saves keystrokes.. but there are risks
-Never in a header file! Only in .cpp
* Has put standard(std) in header file

// IOSTREAM Library
#include<iostream>
-Insertion or output operator <<
-Standard out: std::cout
-Standard error: std:cerr
-End of line: std::endl (preferable over "\n")

-Input operator >>
-Standard input: std::cin


int a, b, c;
std::cin >> a >> b >> c;


// exposing the  std::cout
#include  <iostream>
using  std::cout;

int  main(){
	cout  << "Enter  in 3 numbers: ";
	int a, b, c;
	std::cin  >> a >> b >> c;
	cout  << "You  entered: " << a << ", " << b << ", " << c << std::endl
		  << "Their  average  is: " << (a + b + c)/3.0  << std::endl;
}

// exposing the namespace std
#include  <iostream>
using  namespace std;

int  main(){
	cout  << "Enter  in 3 numbers: ";
	int a, b, c;
	cin  >> a >> b >> c;
	cout  << "You  entered: " << a << ", " << b << ", " << c << endl
		  << "Their  average  is: " << (a + b + c)/3.0  << endl;
}


// STRINGS
#include <string>

std::string is a sequence of char.


/* 
https://en.cppreference.com/w/cpp/string/basic_string
*/

// FOR loop
#include <string>
#include <iostream>
using namespace std;

int main() {
		string s("foobar");
		for(auto c: s) {
				cout << c << endl
		}
	
}

// Compilation
/*
-Preprocessing: Handle lines beginning with "#"
-Compilation: Code translated into assembly
-Assembly: The assembly code is translated into machine code or object code
-Linking: Links the machine code from multiple object files to create an executable
*/

/*
For each source file, you preprocess, compile and assemble
g++ -c -o src_name.o src_name.cpp

For each program, you link:
g++ -o exec_name src_name.o main.cpp
*/

// HEADER files
Usual extension: “.h”; contains:
the class and function prototypes (and the
function comments),
includes of libraries needed for the
prototypes, and
enums (and structs) used in the function
declarations.
Bad form to put using directives in header
files.

// SOURCE files
Source Files Usual extension: “.cpp”; contains:
the function definitions,
includes of libraries needed not already
included in the header,
any other internal enums, structs, etc...

// make sure using c++ version e.g. #include <cstring> not <string.h>


// GOOD PRACTICE! include these in header files
# ifndef IFNDEF_H
# define IFNDEF_H
/* Contents of header file goes here . */
# endif /* IFNDEF_H */


// WATCH OUT FOR TRIGRAPHS!!!
ex. 
??= is eqivalent to #


// Makefiles
# I’m a comment
#CXX will define what compiler we use
CXX=g++
#CXXFLAGS will define what flags we'd like with compilation
#Wall will give us all warnings
CXXFLAGS =- Wall

all: build

module.o: module.h

#make clean will run clean command
clean:
	# these spaces must be tabs
	-rm module.o
	# the - before rm tells it to continue even if there are errors 
	-rm hello

build: main.cpp module.o
	$(CXX) $(CXXFLAGS) -o hello main.cpp module .o


// Put all function comments within the header files

// * What happens in your code depends on the compiler that you use *




// DATE 02/05/2020


// STATIC INT
#include <iostream>
using namespace std;
int g(int a) {
	// this is declared static
	static int b = 0
	b =+ a;
	return b;
}

int main() {
	cout << g(1) << g(2) << endl;
	// out prints 13
	// default 0 is returned
}


// Pointers
// a pointer to an object, an object genral means an
// area in memory, but is also overloaded to mean an instance
// of a class.

// *Like reference in Java

// Arrays are like those in java


// References


// Caveat
#include <iostream>
using namespace std;
int foo() {
	int fooVar = 42;
}
int bar() {
	int barVar;
	cout << barVar;
}
int main() {
	bar();
	foo();
	bar();
}
// This out prints 042
// stack frame for the methods don't get reset.
// In this example foo() and bar() will be given
// an indentically sized stack frame


// MEMORY

// from bottom to top!
// TEXT - all functions -> RAM
// DATA - where global and static is found

// HEAP - read/write you manage this in C++ whereas java has auto garbage collector
// just a heap of memory can pull chuncks as needed

// STACK - locals managed by the compiler, popping and pushing 


// HEAP MEMORY
// *must clean up after yourself!

//Dynamically allocated using the new operator or malloc/calloc/realloc

// The memory is only deallocated when programmer decides - LIFETIME code


//THE STACK

// auto managed by compiler
// faster and no fragmentation
// try and keep everything on stack




// POINTERS
// contain address of of another variable
//

int *aPtr;
int aVar;
aPtr = &aVar;
aVar = 5;
*aPtr = 10;

// Syntax:
// type *ptrName; - Declaration
// & - address of operator

void someFunc(int *aPtr, int bVal){
	bVal = 4;
	*aPtr = 5;
	aPtr = &bVal;
	*aPtr = 7;
}
int main() {
	int i = 1;
	int j = 2;
	// send address of i
	// send a copy of the value in j
	someFunc(&i,j);
	
	printf("i=%d;j=%d",i,j);
}
// this will print out 'i=5;j=2'


// SEG FAULTS

int* foo() {
	int i = 10;
	return &i;
}
int main() {
	int* aPtr = foo();
	// results in seg fault because this address was created
	// from a function's stack frame.
}


// REFERENCE
int *aPtr;
int aVar;
int &aRef = aVar;
aVar = 5;
*aPtr = 10;
aRef = 6;

// Syntax
// type &refName; - Declaration

// * USE REFERENCES OVER POINTERS WHENEVER POSSIBLE *
// however syntactically references don't stand out like references do.


// DATE 02/12/2020

#include <iostream>

using namespace std
int& foo(int& a) {
	return a;
}
int main() {
	int i = 1;
	// unique to C++, foo(int&) returns a reference.
	foo(i) = 5;
	
	cout << i;
	// output will be 5
}

int myFunc(const int a); 
// OR
int  myFunc(int const a);

// promise that this value won't change
const

// STRUCTURES or struct 
// a group of one or more variables. Also, called a record

// struct example Bank Account:
-account numbers

enum typeAcct {CHK, SAV};
struct account {
	long acctNum;
	enum typeAcct acctType;
};

struct account acct1;

struct account acct2 = {12345, CHK};

struct account acct3 = {.acctNum = 123432, .acctType = SAV};

// Structure member operator (.)
cout << acct3.acctNum;
// Outputs 123432

// Pointer to struct 
(*ptrAcct).acctNum;
// OR
ptrAcct->acctNum;

// . has higher precedence than *


// to compare sturcts
// have to go through each member 



// Shallow Copy - copying the bit sof one struct to the other

typedef // a keyword used to create an aliad for another datatype
typedef cType newType

Ex:
typedef long unsigned int size_t;

typedef struct account {
	long acctNum;
	enum typeAcct acctType;
} acct;


// STL overview (Standard Template Library)

// STL is only C++!!!!!!!!!!!

// Containers:
// Vector
// List
// Set
// Map

//Iterators:
// input
// output
// forward
// bidirectional
// random access


// Algorithms:
// sorting
// searching
// max/min
// aggregation

// Functional Objects:
// unary functions
// binary functions


// VECTOR - the dynamic array list
// c++ equivalent of ArrayList

// On the Stack:
vector <int > v1; // Empty vector
vector <int > v2(v1 ); // Copy of v1
vector <int > v3 = v1; // Copy of v1
vector <int > v4 (10 ,42); // Ten 42s
vector <int > v5 (10); // Ten 0s
vector <int > v6 {1 ,2 ,3 ,4 ,5}; //1 to 5
vector <int > v7 = {1 ,2 ,3 ,4 ,5}; //1 to 5

// On the Heap:
vector <int > *p1; // Vector pointer , unassigned
vector <int > *p2 = new vector <int >; // Vector pointer
vector <int > *p3 = &v2; // Copy of addr of v2
vector <int > *p4 = new vector <int >(10 ,42); // Ten 42s
vector <int > *p5 = new vector <int >(10); // Ten 0s
vector <int > *p6 = new vector <int >{1 ,2 ,3 ,4 ,5}; //1 to 5

// Status
v.size(); // number of elements
v.capacity(); // number of elements that can be held in reserved spaces

// Adding/Removing
v.push_back(7); // add to the back
v.pop_back(7); // remove last item

// Random Access
v[0] =  7; // (0-based indexing)
int i = v[3];


// Iterators
vector<int>::iterator ite = v.begin();
// auto means we don't need to worry about getting the right value type
auto jtr = v.begin();
/*
	Forward: v.begin() (first element)/ v.end() (one past
	last element)
	Constant Forward (C++11): v.cbegin() / v.cend()
	Reverse: v.rbegin() / v.rend()
	Constant Reverse (C++11): v.crbegin() / v.crend()
*/

// member functions using iterators
v.insert(itr, 1); // Insert before itr. (There are other insert variants.)
v.erase(itr); // Remove item at itr. (Invalidates itr.)
v.erase(itr,jtr); // Remove items

// Range based for loop
vector <int > v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
for ( auto &i : v)
{
	cout << i << " ";
}

// OR using an iterator

for ( auto itr = v. begin(); itr != v.end(); ++itr )
{
cout << *itr << " ";
}

// iterator example:

// Erase all even numbers (C ++11 and later )
auto jtr = v. begin ();
// make sure you get an updated iterator v.end()
while (jtr != v.end ())
{
	if (* jtr % 2 == 0) {
		jtr = v. erase (jtr );
	} else {
		++ jtr;
	}
}


// vector example:
# include <vector >
# include <iostream >
using namespace std;
int main ()
{
	vector <char> v{’a’,’b’,’c’,’d’,’e’};
	
	cout << v; // compilation error
	cout << &v; // memory address
}


// SORTING Basics
#include <algorithm>

// must define function f which works as your comparison.
# include <vector >
# include <algorithm >
# include <iostream >
using namespace std;
bool f( const int &a, const int &b)
{
	if(a % 2 == 0 && b % 2 != 0)
		return true ;
	if(a % 2 != 0 && b % 2 == 0)
		return false ;
	return a > b;
}
int main ()
{
	vector <int > v{1 ,2 ,3 ,4 ,5};
	sort (v.begin(), v.end(), f);
	for ( auto &i: v)
		cout << i;
}



// DATE 02/19/2020

// TODO for program!!!!!!!!!
// do c++ style casting, write own method descriptions


// ASSOCIATIVE CONTAINERS

//map - key-value pairs; unique keys
//set - key-value pairs; unique keys
//multimap - repeated keys
//multiset - repeated keys

// map
// k is the key
m[k] = "foo" // Updates/inserts, at key k, the value "foo".
bar = m[k] // Retrieves the value at key k.
//Note m[k] adds k with empty value if key doesn’t exist.


// all values in map are stored as pair<T1, T2> p
//Elements in a map are stored as pairs.
p.first // First data member (key in a map)
p.second // Second data member (value in a map)

// Range-based for
for ( auto &p : m)
{
	cout << "key: " << p. first << endl
	<< " value : " << p. second << endl ;
}

// I/O
// given the input "2.5 2.5 2.5"
int a;
double b;
string c;
cin >> a >> b >> c;
cout << a << b << c;

// output = 2.52.5


// good idea to test stream.good() before computation
if(s) {.....} // tests s.good()
while (s >> a) {....}


// closing stream
s.close() // automatically flushes the stream

// a stream has ONE Marker. All operations happen relative to that marker.
seekg(pos) / seekp(pos) // set marker to absolute position of pos.

// I/O streams only have one marker



// ARRAYS
// C++ Heap Allocation (recommended)
int *a = new int[10]; // or
int *a = new int[10](); // zeros memory or
int *a = new int[10]{1,2,3,4,5,6,7,8,9,10}; //(C++11)

// Preventing Memory Leaks
// If you new [], you need to delete [] the memory!
delete [] a;




// DATE 02/26/2020

// Classes and the Rule of 3


// CLASSES
// provide a way of defining new types that
// group member variables and functions.

// Access COntol
public // members are accessible outside the class
private // members are only accessible inside the classs to its friends
protected // only accessible inside class, derived classes, and friends

// Class vs Struct
class is private
struct is public

/*Usual Practice: struct used for simple containers */



// ORGANIZING C++ CLASSES






