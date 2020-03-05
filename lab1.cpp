#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class Test {
    int a;
public:
    Test() {
        a = 0;
        cout << &a << endl;
    }

    void prt() {
        cout << &a << endl;
    }
};

Test &foo(Test &b) {

    return b;
}

int main() {

    Test a ;
    Test &b = foo(a);
    b.prt();


    return 0;
}
