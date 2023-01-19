#include <iostream>

// 2.3 Arrays

using namespace std;


int main() {
	
	int a[5] = {1, 2, 3, 4, 5};
	
	cout << "a[3]: " << a[3] << endl;
	cout << "*(a + 3): " << *(a + 3) << endl;
	cout << "3[a]: " <<  3[a] << endl;

	// array to pointer conversion
	int*p = a;
	cout << "*(p + 2): " << *(p + 2) << endl;
	cout << "p[2]: " << p[2] << endl;

	// p points to 3rd element
	p = a + 2;
	cout << "p[-2]: " << p[-2] << endl;
	
	
	cout << "sizeof(array): " << sizeof(a) << endl;
	cout << "sizeof(pointer): " << sizeof(p) << endl;
	
	//dynamic array initialization
	int* pa = new int[100];
	delete[] pa;




	return 0;
}
