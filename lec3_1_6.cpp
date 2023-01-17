#include <iostream>
#include <string>

using namespace std;

int main() {
	int a = 0;
  	int b = 1;
	int c = 0;
  //	if (a++ && b++) {
//
  //	}
  //	cout << a << " " << b;
  //
 
	a = 0;
	b = 1;
	if (b++ || a++) {
	}
	cout << a << " " << b << endl;


	a = 0; b = 1; c = 2;
	a = b = c;
	cout << a << " " << b << " " << c << endl;
	
	//cout << (2 < 3 ? 333 : "abc");
	string s = "abc";
	string ss = "abcdefghijklmno";
	cout << (2 < 3 ? ss : s).size();
	cout << endl;
	

	
	int  j = (a = 12, b = 14, c = 17);	
	cout << "My " << j << endl;

	return 0;
}

