#include <iostream>
#include "mystring.h"
//#include "mypair.h"
using namespace std;
using namespace mystl;


int main(int argc, char const *argv[])
{
	mystring str("Hello");

	mystring newstr = str;

	cout << newstr << endl;
	/* code */
	return 0;
}
