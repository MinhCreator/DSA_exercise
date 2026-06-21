#include <iostream>

using namespace std;


// combine using pointer
void addition(double *a, double b) {
    * a += b;
}


void subtraction(double *a, double b) {
    * a -= b;
}


void multiplication(double *a, double b) {
    * a *= b;
}


void division(double *a, double b) {
    * a /= b;
}

int main() {

    double a = 10.0;

    addition(&a, 5.0);
    cout << a << endl;
    subtraction(&a, 5.0);
    cout << a << endl;
    multiplication(&a, 5.0);
    cout << a << endl;
    division(&a, 5.0);
    cout << a << endl;
    return 0;
}