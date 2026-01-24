#include<bitset>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Tset {
    public:
        Tset(string d) {
            int c;
            for (int i = 0; i < 256 && d[i] != '\0'; i++) {
                c = (int)d[i];
                data[c] = 1;
            }
            ++count;
            if (count % 2 == 0) name = 'B';
            else name = 'A';
        }
        void display() {
            cout << ": {";
            for (int i = 0; i < 256; i++) {
                if (data[i]) {
                    cout << (char)i;
                }
            }
            cout << '}' << endl;
        }
        friend bool operator==(const Tset& A, const Tset& B) {
            return A.data == B.data;
        }
        friend Tset operator+(const Tset &A, const Tset &B) {
            Tset result;
            result.data = A.data | B.data;
            return result;
        }
        friend Tset operator-(const Tset &A, const Tset &B) {
            Tset result;
            result.data = A.data & (~B.data);
            return result;
        }
        friend Tset operator*(const Tset &A, const Tset &B) {
            Tset result;
            result.data = A.data & B.data;
            return result;
        }
        friend bool operator>=(const Tset &A, const Tset &B) {
            return A * B == B;
        }
        void in(char s) {
            int idx = static_cast<unsigned char>(s);  // To prevent negative indexing
            if (data[idx]) {
                cout << '\'' << s << "' is in " << name << endl;
            } else {
                cout << '\'' << s << "' is not in " << name << endl;
            }
        }
        friend void out(Tset &A, Tset &B, char s);
    private:
        bitset<256> data;
        static int count;         // static member belongs only to the hole class
        Tset() : name('?') {};    // To let variable be created in operator overloading functions without misleading "count"
                                  // and pre-name "name" as '?' and using "{}" to ignoere other initialization
        char name;
};

void out(Tset &A, Tset &B, char s) {
    cout << A.name;
    A.display();
    cout << B.name;
    B.display();
    Tset result = A + B;
    cout << "A + B";
    result.display();
    result = A * B;
    cout << "A * B";
    result.display();
    result = A - B;
    cout << "A - B";
    result.display();
    result = B - A;
    cout << "B - A";
    result.display();
    if (A >= B) cout << A.name << " contains " << B.name << endl;
    else cout << A.name << " does not contain " << B.name << endl;
    if (B >= A) cout << B.name << " contains " << A.name << endl;
    else cout << B.name << " does not contain " << A.name << endl;
    A.in(s);
    B.in(s);
}

int Tset::count = 0;         // initialize static member outside the class

int main() {
    int times;
    cin >> times;
    int t = 0;
    vector<string> inputs;
    while (t != times) {
        string us, cs, s;
        cin >> us >> cs >> s;
        inputs.push_back(us);
        inputs.push_back(cs);
        inputs.push_back(s);
        t++;
    }
    for (int i = 0; i < inputs.size(); i += 3) {
        Tset A(inputs[i]), B(inputs[i + 1]);
        out(A, B, inputs[i + 2][0]);
    } 
    return 0;     
}