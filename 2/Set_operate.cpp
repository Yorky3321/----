#include<iostream>

using namespace std;

class Tset {
    public:
        Tset(char *d, char *c, char s) {
            for (int i = 0; i < 256; i++) {
                data[i] = d[i];
                comp[i] = c[i];
            }
        }
    private:
        char data[256];
        char comp[256];
        char special;
}