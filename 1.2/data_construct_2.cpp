#include <iostream>

using namespace std;

int main() {
    cout << "Calcutating factorial of :" << endl;
    int n = 0;
    cin >> n;
    int A[80] = {0};
    int from = 79;                /* tarageting the strating position of array A*/
    A[79] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 80; j++) {
            if (A[j] == 0) continue;
            A[j] = A[j] * i;
            if (j < from) {
                from = j;               /* Renew from */ 
            }      
        }
        for (int j = 79; j >= from; j--) {
            if ((A[j] / 10) > 0 && j > 0) {
                A[j - 1] += A[j] / 10;
                if (j == from) from--;
            }
            A[j] %= 10;            
        }
    }
    for (int i = from; i < 80; i++) {                
        cout << A[i];
    }
    return 0;
}