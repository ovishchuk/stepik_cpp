/* main.cpp step-4.6-1 */
#include <iostream>
using namespace std;


class A {
public:
    int aPub;
    virtual ~A() {}
    //virtual int getPub() { return aPub; }
protected:
    int aProt;
private:
    int aPriv;
    virtual int getPub() {return aPub;}
};


class B: public A {
    int getPub() { return aPub; }
};

int main(){
    B bObj;
    bObj.aPub = 3;
    //cout << bObj.getPub() << endl;
    return 0;
}