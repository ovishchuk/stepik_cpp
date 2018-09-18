#include <iostream>

int power(int x, unsigned p) {
	int answer = x;
	for (int i = 1; i < p; ++i) {
		answer *= x;
	}
	return answer;
}

int main() {
	std::cout << power(0, 0) << std::endl;
	return 0;
}
