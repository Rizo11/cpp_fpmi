#include <iostream>

using namespace std;

void f(int a) {
	static int x = 0;
	cout << "static int from f(): "<< x << endl;
	++x;
}


int main_static() {

	// will be saved in stack
	int a;
	cout << "Adress of int a: " << &a << endl;

	{
		double x = 3.14;
		cout << "Addres of double x: " << &x << endl;
	}

	{
		double y;
		cout << "Address of double y: " << &y << endl;
	}
	
	// undefined behavior
	cout << "value of x: " << *(double*)(&a+1) << endl;
	
	f(1);
	f(1);


	return 0;
}


int main() {
	int a;
	cout << &a << '\n' << endl;
	
	int* p = new int(5);
	cout << "Dynamic \n";
	cout << "value of p: " << *p << endl;
	cout << "address of p: " << p << endl;
	pp = p;
	delete p;
}
