#include <iostream>
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
        for (const auto& row : A) {
            for (const auto& val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
