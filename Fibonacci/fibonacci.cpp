#include <iostream>

using namespace std;

int fibonacci(int n) {
    int a = 0, b = 1;
    if (n == 0) return a;
    else if (n == 1) return b;
    else if (n > 1) return fibonacci(n - 1) + fibonacci(n - 2);
    else {
        cout << "Error input!" << endl;
        return -1;
    }
}

void main() {
    int n;
    cout << "Enter the position of Fibonacci number: ";
    cin >> n;
    cout << "Fibonacci number at position " << n << " is " << fibonacci(n) << endl;
}