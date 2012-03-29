// FILE: mystring.h
// CLASS PROVIDED: mystring (a sequence of characters)
//
// CONSTRUCTOR for the mystring class:
//   mystring(const char str[ ] = "") -- default argument is the empty string.
//     Precondition: str is an ordinary null-terminated string.
//     Postcondition: The string contains the sequence of chars from str.
//
// CONSTANT MEMBER FUNCTIONS for the mystring class:
//   size_t length( ) const
//     Postcondition: The return value is the number of characters in the
//     string.
//
//   char operator [ ](size_t position) const
//     Precondition: position < length( ).
//     Postcondition: The value returned is the character at the specified
//     position of the string. A string's positions start from 0 at the start
//     of the sequence and go up to length( )-1 at the right end.
//
// MODIFICATION MEMBER FUNCTIONS for the mystring class:
//   void operator +=(const string& addend)
//     Postcondition: addend has been catenated to the end of the string.
//
//   void operator +=(const char addend[ ])
//     Precondition: addend is an ordinary null-terminated string.
//     Postcondition: addend has been catenated to the end of the string.
//
//   void operator +=(char addend)
//     Postcondition: The single character addend has been catenated to the
//     end of the string.
//
//   void reserve(size_t n)
//     Postcondition: All functions will now work efficiently (without
//     allocating new memory) until n characters are in the string.
//
// NON-MEMBER FUNCTIONS for the mystring class:
//   mystring operator +(const mystring& s1, const mystring& s2)
//     Postcondition: The string returned is the catenation of s1 and s2.
//
//   istream& operator >>(istream& ins, mystring& target)
//     Postcondition: A string has been read from the istream ins, and the
//     istream ins is then returned by the function. The reading operation
//     skips white space (i.e., blanks, newlines, tabs) at the start of ins.
//     Then the string is read up to the next white space or the end of the
//     file. The white space character that terminates the string has not
//     been read.
//
//   ostream& operator <<(ostream& outs, const mystring& source)
//     Postcondition: The sequence of characters in source has been written
//     to outs. The return value is the ostream outs.
//
//   void getline(istream& ins, mystring& target)
//     Postcondition: A string has been read from the istream ins. The reading
//     operation reads all characters (including white space) until a newline
//     or end of file is encountered. The newline character is read and
//     discarded (but not added to the end of the string).
//
//  VALUE SEMANTICS for the mystring class:
//    Assignments and the copy constructor may be used with mystring objects.
//
//  TOTAL ORDER SEMANTICS for the mystring class:
//    The six comparison operators (==, !=, >=, <=, >, and <) are implemented
//    for the mystring class, forming a total order semantics, using the usual
//    lexicographic order on mystrings.
// 
// DYNAMIC MEMORY usage by the mystring class: 
//   If there is insufficient dynamic memory then the following functions call
//   new_handler: The constructors, reserve, operator +=, operator +, and the
//   assignment operator.

#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>  // Provides size_t

namespace mystl
{
	class mystring
	{
	public:
		// CONSTRUCTORS and DESTRUCTOR
		//mystring(void);
		mystring(const char* str = "");
		mystring(const mystring& source);
		~mystring( );
		// MODIFICATION MEMBER FUNCTIONS
		void operator +=(const mystring& addend);
		void operator +=(const char* addend);
		void operator +=(char addend);
		
		void clear(void);
		const char* c_str();


		void reserve(std::size_t n);
		const mystring& operator =(const mystring& source);
		// CONSTANT MEMBER FUNCTIONS
		std::size_t length() const { return current_length; }
		const char& operator [](size_t position) const;
		// FRIEND FUNCTIONS
		friend std::ostream& operator <<(std::ostream& outs, const mystring& source);
		//friend std::istream& operator>> (std::istream& is, mystring& str);
		friend bool operator ==(const mystring& s1, const mystring& s2);
		friend bool operator !=(const mystring& s1, const mystring& s2);
		friend bool operator >=(const mystring& s1, const mystring& s2);
		friend bool operator <=(const mystring& s1, const mystring& s2);
		friend bool operator > (const mystring& s1, const mystring& s2);
		friend bool operator < (const mystring& s1, const mystring& s2);
		//friend const mystring& operator+(const mystring& origin, const mystring& addend);
		//friend std::istream& getline (std::istream& is, mystring& str );
	private:
		char *sequence;
		size_t allocated;
		size_t current_length;
	};

	// NON-MEMBER FUNCTIONS for the mystring class
	mystring operator +(const mystring& s1, const mystring& s2);
	std::istream& operator >>(std::istream& ins, mystring& target);
	std::istream& getline(std::istream& ins, mystring& target);
}

#endif
