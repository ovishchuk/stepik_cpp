#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a, b, c;
	
	cin >> a >> b >> c;
	if (a) { // "a != 0"
		if (b == 0 && c == 0) { // "ax^2 = 0"
			cout << b << " " << c << endl;
		} else if (b == 0) { // "ax^2 + c = 0"
			// "-(c/a) < 0"
			if (-(c/a) < 0) {cout << "No real roots\n";}
			// "-(c/a) > 0"
			else { cout << (sqrt(-(c/a))) << " " << (-(sqrt(-(c/a)))) << endl;}
 		} else if (c == 0) { // "ax^2 + bx = 0"
 			// "x_1 = 0; x_2 = -(b/a)"
 			cout << 0 << " " << (-(b/a)) << endl;
 		} else { // "ax^2 + bx + c = 0"
 			// "D = b^2 - 4ac"
 			// D = ((b * b) - (4 * a * c));
 			// "D < 0"
 			if (((b * b) - (4 * a * c)) < 0) {cout << "No real roots\n";}
 			// "D = 0"; "x = -b/2a"
 			else if (((b * b) - (4 * a * c)) == 0) {cout << ((-b) / (2 * a)) << " " << ((-b) / (2 * a)) << endl;}
 			// "D > 0; x_1 = (-b + sqrD)/(2a); x_2 = (-b - sqrD)/(2a)"
 			else {cout << ((-b + sqrt(((b * b) - (4 * a * c)))) / (2 * a)) << " " << ((-b - sqrt(((b * b) - (4 * a * c)))) / (2 * a)) << endl;}
 		}
	}
	return 0;
}
