#include <iostream>
using namespace std;


void reverse (int array[], unsigned size) {
	int tmp; // для хранения заменяемого значения элемента массива
	int tail;
	for (unsigned i = 0; i < (size - (size % 2)) / 2; i++) {
		// симметричная перестановка эл. масс.
		tmp = array[i];
		tail = size - (i+1);
		array[i] = array[tail];
		array[tail] = tmp;
	}
}

void rotate (int a[], unsigned size, int shift) {
	for (unsigned i = 0; i < (unsigned)shift; i++) {
		reverse(a, size);
		reverse(a, size - 1);
	}
}

int main() {
	unsigned size = 6;
	int m[size] = {1, 2, 3, 4, 5, 6};
	rotate(m, size, 3);
	for (unsigned i = 0; i < size; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
    return 0;
}
