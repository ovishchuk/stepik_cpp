#include <iostream>
using namespace std;

int main() {
	int a, p, T;
	cin >> T;
	while (T > 0) {
		p = 0;
		cin >> a;
		if (a < 1000000000 && a >= 1) {
			int tmp = 2;
			do {
				tmp *= 2;
				p++;
			} while (tmp <= a);
			cout << p << endl;
		}
		T--;
	}
	return 0;
}
