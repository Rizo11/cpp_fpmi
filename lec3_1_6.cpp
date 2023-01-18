#include <iostream>
#include <string>

using namespace std;

int f(int a, int b) {
	cout << "inside func: " << a << " " << b << endl;
	return 0;
}
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
	
	a = 0;
	/* ++a = a++;
	cout << a << endl;
	cout << "new---------" << endl;
	int i = 0;*/
	//i = ++i + 2;       // well-defined
	//i = i++ + 2;       // undefined behavior until C++17
	//f(i = -2, i = -2); // undefined behavior until C++17
	//f(++i, ++i);       // undefined behavior until C++17, unspecified after C++17
	//i = ++i + i++;
	//cout << i << endl;
	
	
	//(a, b) = 17;
	//cout << a << " " << b << endl;
	
	
	double d = 3.14;	
	double* p = &d;
	double* pp = p + 1;
	cout << "pp - p: " << pp-p << endl;

	
	return 0;
}

