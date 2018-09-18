#include <iostream>
using namespace std;

int main()
{
    bool flag = false;
    char c = '\0';
    while (cin.get(c)) {
        if (c == ' ' && !flag) {
        	cout << c;
        	flag = true;
        }
        if (c != ' '){
        	cout << c;
        	flag = false;
        }
    }
	return 0;
}
