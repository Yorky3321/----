#include <iostream>
using namespace std;

void permutation(char *n, int x = 0, int y = 0){
    if (x == y) {
        for (int i = 0; i <= y; i++) cout << n[i];
        cout << endl;
    }else if (x < y) {
        for (int i = x; i <= y; i++) {
            swap(n[x], n[i]);
            permutation(n, x + 1, y);
            swap(n[x], n[i]);
        }
    } else {
        cout << "Error input!" << endl;
    }
}

int main(){
    char n[10];
    n[0] = 'A', n[1] = 'B', n[2] = 'C', n[3] = 'D', n[4] = 'E', n[5] = 'F', n[6] = 'G', n[7] = 'H', n[8] = 'I', n[9] = 'J';
    permutation(n, 0, 4);
    return 0;
}