#include <bitset>
#include <iostream>

using namespace std;

void main() {
    cout << "Insert some characters:" << endl;
    char input[256];
    bitset<256> set;
    int c;
    cin >> input;
    for (int i = 0; i < 256 && input[i] != '\0'; i++) {
        c = (int)input[i];
        if (set[c] == 0) {
            set[c] = 1;
        }
    }
    for (int i = 0; i < 256; i++) {
        if (set[i]) {
            cout << (char)i << " ";
        }
    }
}