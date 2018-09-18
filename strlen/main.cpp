#include <iostream>

unsigned strlen(const char *str) {
	unsigned length = 0;
	while (*str++) length++;
	return length;
}


int main(int argc, char** argv) {
	const char* msg = argv[1];
	std::cout << strlen(msg) << std::endl;
	return 0;
}
