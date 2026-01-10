#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    cout<<"Please enter an odd number:"<<endl;
    int n;
    cin>>n;
    while (n%2==0)
    {
        cout<<"Please enter an odd number:"<<endl;
        cin>>n;
    }
    for (int i = 1; i <= n; i += 2) {
        cout << endl;
        int r = 0;
        int c = (i + 1) / 2 - 1;
        vector<vector<int>> A(i, vector<int>(i, 0));
        A[r][c] = 1;
        for (int y = 2; y <= i * i; ++y) {
            if (r == 0) r = i - 1;
            else --r;
            if (c == i - 1) c = 0;
            else ++c;
            if (A[r][c] != 0) {
                if (r == i - 1) r = 0;
                else r ++;
                if (c == 0) c = i - 1;
                else c --;
                if (r == i - 1) r = 0;
                else r ++;
            }
            A[r][c] = y;
        }
        cout << "Origin" << "  |  " << "Vert flap" << "  |  " << "R.turn" << "  |  " << "L.turn" << "  |  " << "Eqat flap" << endl;
        for (int x = 0; x < i; x++) {
            for (int y = 0; y < i; y++) {
                cout << left << setw(3) << A[x][y];
            }
            cout << "  " << "|  ";
            for (int y = i-1; y >= 0; y--) {
                cout << left << setw(3) << A[x][y];
            }
            cout << "  " << "|  ";
            for (int y = i-1; y >= 0; y--) {
                cout << left << setw(3) << A[y][x];
            }
            cout << "  " << "|  ";
            x = i - x - 1;
            for (int y = 0; y < i; y++) {
                cout << left << setw(3) << A[y][x];
            }
            cout << "  " << "|  ";
            for (int y = 0; y < i; y++) {
                cout << left << setw(3) << A[x][y];
            }
            cout << endl;
            x = i - x - 1;
        }
    }
    return 0;
}
