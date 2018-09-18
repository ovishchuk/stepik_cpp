#include <iostream>
using namespace std;
 
void reverse() {
    unsigned int x;
    if (cin >> x && x !=0) {
        reverse();
        cout << x << " ";
    }
}
 
int main() {
    reverse();
    return 0;
}
