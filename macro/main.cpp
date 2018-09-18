#include <iostream>
#define MAX(x, y, r) {\
int a = x;\
int b = y;\
a > b ? r = a : r = b;}


int main() {
	int x = 7;
	int y = 12;
	int r = 0;
	MAX(x, y, r);
	std::cout << r << std::endl;
	MAX(x += y, y, r);
	std::cout << r << std::endl;
	return 0;
}
