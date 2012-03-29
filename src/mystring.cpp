
#include "mystring.h"
#include <assert.h>

using namespace std;

//mystring::mystring(void):
//sequence(NULL), allocated(0), current_length(0)
//{
//}
namespace mystl
{
	mystring::mystring(const char* str /* = "" */)
	{
		size_t len = strlen(str);
		sequence = new char[len + 1];
		strcpy(sequence,  str);
		allocated = len + 1;
		current_length = len;
	}

	mystring::mystring(const mystring& source)
	{
		size_t len = strlen(source.sequence);
		sequence = new char[len + 1];
		strcpy(sequence, source.sequence);
		allocated = len + 1;
		current_length = len;

	}

	void mystring::clear()
	{
		delete[] sequence;
		sequence = NULL;
		allocated = 0;
		current_length = 0;
	}

	const char* mystring::c_str()
	{
		return sequence;
	}

	mystring::~mystring()
	{
		delete [] sequence;
		sequence = NULL;
		current_length = 0;
		allocated = 0;
	}

	void mystring::operator+=(const mystring& addend)
	{
		size_t len = strlen(addend.sequence);
		char* temp = new char[current_length + len + 1];
		strcpy(temp, sequence);
		delete[] sequence;
		sequence = NULL;
		strcat(temp, addend.sequence);
		sequence = temp;
		current_length = current_length + len;
		allocated = current_length + 1;
	}

	void mystring::operator+=(const char* addend)
	{
		size_t len = strlen(addend);
		char* temp = new char[current_length + len + 1];
		strcpy(temp, sequence);
		delete[] sequence;
		sequence = NULL;
		strcat(temp, addend);
		sequence = temp;
		current_length = current_length + len;
		allocated = current_length + 1;
	}

	void mystring::operator+=(char addend)
	{
		char* temp = new char[allocated + 1];
		strcpy(temp, sequence);
		delete sequence;
		sequence = NULL;
		temp[current_length] = addend;
		temp[current_length + 1] = '\0';
		sequence = temp;
		++current_length;
		allocated = current_length + 1;
	}

	mystring operator+(const mystring& origin, const mystring& addend)
	{
		mystring temp = origin;
		temp += addend;
		return mystring(temp);
	}

	void mystring::reserve(size_t n)
	{
		sequence = new char[n];
		allocated = n;
		current_length = 0;
	}

	const mystring& mystring::operator=(const mystring& source)
	{
		if (this != &source)
		{
			delete[] sequence;
			size_t len = strlen(source.sequence);
			sequence = new char[len + 1];
			strcpy(sequence,  source.sequence);
			allocated = len + 1;
			current_length = len;
		}
		return *this;
	}

	const char& mystring::operator[](size_t position) const
	{
		assert(position >= 0 && position < current_length);
		return sequence[position];
	}

	ostream& operator <<(ostream& outs, const mystring& source)
	{
		outs << source.sequence;
		return outs;
	}

	istream& operator >>(istream& is, mystring& target)
	{
		char temp[128];
		is>>temp;
		target.clear();
		target = mystring(temp);
		return is;
	}


	bool operator== (const mystring& s1, const mystring& s2)
	{
		if (1 == strcmp(s1.sequence, s2.sequence))
		{
			return true;
		}
		return false;
	}

	bool operator!= (const mystring& s1, const mystring& s2)
	{
		if (1 != strcmp(s1.sequence, s2.sequence))
		{
			return true;
		}
		return false;
	}

	bool operator>= (const mystring& s1, const mystring& s2)
	{
		return strcmp(s1.sequence, s2.sequence) >= 1;
	}

	bool operator<= (const mystring& s1, const mystring& s2)
	{
		return strcmp(s1.sequence, s2.sequence) <= 1;
	}

	bool operator> (const mystring& s1, const mystring& s2)
	{
		return strcmp(s1.sequence, s2.sequence) > 0;
	}

	bool operator< (const mystring& s1, const mystring& s2)
	{
		return strcmp(s1.sequence, s2.sequence) < 0;
	}

	istream& getline(istream& is, mystring& target)
	{
		char temp[128];
		is>>temp;
		target.clear();
		target = mystring(temp);
		return is;
	}
}