#include <iostream>

// global scope
int x = 0;

namespace N {
	int x = 1;	
}

struct S {
	int x;
};

int main() {
	int x = 4;

	//referring to the global x = 0;
	std::cout << ::x;
	{
		int x = 5;
		// referring to the global x = 0
		std::cout << ::x;
	}
	// referring to local x = 4
	std::cout << x;
	std::cout << N::x;

}
