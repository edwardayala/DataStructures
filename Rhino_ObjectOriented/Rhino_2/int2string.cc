#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int tag = 123;
	int tag2 = -23;

	stringstream stag;

	stag << tag;
	cout << (tag > 0? "Tag " + stag.str():"") << endl; 
	
	stag << tag2;
	cout << (tag2 > 0? "Tag " + stag.str():"") << endl; 

	return 0;
}
