#include <iostream>
#include <vector>

using namespace std;


class knight {
    private:
        const int move[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
        int x, y, n, nx, ny, count;
        vector<vector<int>> trace; 
        vector<int> last_move;
    public:
        knight(int size){
            x = 0;
            y = 0;
            n = size;
            count = 0;
            trace.assign(n, vector<int>(n, 0));
            last_move.assign(n*n, 0);
            trace[0][0] = 1; // Starting position
        }
        bool is_valid(int x, int y) {
            return (x >= 0 && x < n && y >= 0 && y < n && trace[x][y] == 0);
        }
        bool finish() {
            return (count == n*n - 1); // All squares visited
        }
        int travel() {
            for (int i = 0; i < 8; i++) {
                nx = x + move[i][0];
                ny = y + move[i][1];
                if (is_valid(nx, ny)) {
                    x = nx;
                    y = ny;
                    last_move[count] = i;
                    trace[nx][ny] = ++count + 1; // Mark the move
                    travel(); // Recur with the new position
                }
            }
            if (finish()) {
                return 0; // All squares visited
            } else if (count == 0) {
                trace[x][y] = 0; // Backtrack
                return -1; // no solution found
            } else {
                trace[x][y] = 0; // Backtrack
                x -= move[last_move[count-1]][0];
                y -= move[last_move[count-1]][1];
                count--;
                return 1; // Backtrack to previous position
            }
        }
        void print() {
            if (trace[0][0] == 0) {
                cout << "No solution found." << endl;
                return;
            } else {
                for (const auto& row : trace) {
                    for (const auto& cell : row) {
                        cout << cell << "\t";
                    }
                    cout << endl;
                }
            }
        }
};


void main() {
    int num[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    for (int i : num) {
        cout << "Knight's Tour for " << i << "x" << i << " board:" << endl;
        knight k(i);
        k.travel();
        k.print();
        cout << endl;
    }
}