#include <iostream>

int count = 0;

int foo(int n) {
    count++;
    if (n <= 0)
        return 1;
    return foo((n * 2) / 3) + foo(n - 2);
}

int main() {
	foo(300);
	std::cout << count << std::endl;
	return 0;
}
