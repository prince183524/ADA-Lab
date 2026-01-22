#include <iostream>
using namespace std;

int main() {
    int n, x;

    cout << "Enter degree of polynomial: ";
    cin >> n;

    int a[100];

    cout << "Enter coefficients (from highest degree to constant term):\n";
    for(int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    cout << "Enter value of x: ";
    cin >> x;

    // Horner's Method
    int result = a[0];
    for(int i = 1; i <= n; i++) {
        result = result * x + a[i];
    }

    cout << "\nValue of polynomial = " << result;

    return 0;
}