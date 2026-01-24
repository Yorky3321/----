#include<iostream>

using namespace std;

class Tset {
    public:
        Tset(char *d, char s) {
            for (int i = 0; i < 256 && d[i] != '\0'; i++) data[i] = d[i];
            special = s;
        }
        void display() {
            for (int i = 0; i < 256 && data[i] != '\0'; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
    private:
        char data[256] = {0};
        char special;
};

int main() {
    cout << "Set Operations :" << endl;
    char us[256], cs[256];
    cin >> us >> cs;
    Tset A(us, 0);
    Tset B(cs, 0);
    A.display();
    B.display();
    return 0;
}