#include <iostream>


unsigned gcd(unsigned a, unsigned b) {
	if (b == 0)
	    return a;
	return gcd(b, a % b);
}

int main() {
	std::cout << gcd(5, 12134679) << std::endl;
	return 0;
}
