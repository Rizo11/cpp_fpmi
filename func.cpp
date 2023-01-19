#include <iostream>

// 2.4 Functions.

using namespace std;

void f(int x) {
	cout << "int arg: " << x << endl;
}

int f_d(double x) {
	cout << "double arg: " << x << endl;
	return 1;
}

double f_d(int x) {
	cout << "int arg: " << x << endl;
	return 2.1;
}

void f(float x) {
	cout << "float arg: " << x << endl;
}



int main() {
	
	//f(0.0);
	//f(2);

	double a = f_d(0.0);
	cout << a << endl;
	int b = f_d(2);
	cout << b << endl;
	return 0;
}
