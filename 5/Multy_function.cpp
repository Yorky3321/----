#include <iostream>
using namespace std;

class structnode {
    public:
        int coeff;
        int exp;
        structnode* next;
};

class polynomial {
    public:
        polynomial(int coeff, int exp, structnode* h = 0) {
            head = new structnode;
            head->coeff = coeff;
            head->exp = exp;
            head->next = h;
        }
    private:
        structnode* head;
};