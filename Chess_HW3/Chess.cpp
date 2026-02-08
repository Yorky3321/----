#include <iostream>
#include <vector>

using namespace std;

class Stack {
    public:
        Stack(int size){
            amount = size;
            arr = vector<vector<int>>(amount, vector<int>(3, 0));
            last = -1;                 // Initialize last to -1 to indicate an empty stack
        }
        void look(int &x, int &y, int &m) {
            x = arr[last][0];
            y = arr[last][1];
            m = arr[last][2];
        }
        void push(int x, int y, int m) {
            last++;
            arr[last][0] = x;
            arr[last][1] = y;
            arr[last][2] = m;
        }
        void pop() {
            if (last > -1) {
                last--;
            }
        }
        void print() const {
            for (int i = 0; i < last; i++) {
                cout << '(' << arr[i][0] + 1 << ", " << arr[i][1] + 1 << ") -> "; // Adjusting back to 1-based indexing
            }
            cout << "END" << endl;
        }
        bool is_empty() const {
            if (last == -1) return true;
            return false;
        }
    private:
        int amount, last;
        vector<vector<int>> arr;
};

class knight {
    public:
        knight(int num, int posx, int posy) {
            n = num;
            x = posx - 1;  // Adjusting for 0-based indexing
            y = posy - 1;
            m = 0;
            trace = vector<vector<bool>>(n, vector<bool>(n, false));
            movement = new Stack(n*n);
            count = 0;
        } 
        void move_knight() {
            trace[x][y] = true;
            movement->push(x, y, 0);
            while (count < n*n) {
                if (count == 3) {
                    cout << "Debug" << " | ";
                }
                x += move[m][0];          // next position
                y += move[m][1];
                while (x < 0 || x >= n || y < 0 || y >= n || trace[x][y]) {
                    movement->look(x, y, m);  // Backtrack to the last position 
                    movement->pop();          // To update the move index
                    m++;                      // Try next move
                    while (m > 7) {
                        // Backtrack if all moves are exhausted
                        if (movement->is_empty()) {
                            cout << "No solution found." << endl;
                            return;
                        } 
                        trace[x][y] = false;
                        movement->look(x, y, m);
                        movement->pop();
                        count--;
                        m++;
                    }
                    movement->push(x, y, m);  
                    x += move[m][0];          // Update again
                    y += move[m][1];
                    m = 0;                      // Reset move index for the next position
                } 
                trace[x][y] = true;
                movement->push(x, y, m);
                m = 0;                      // Reset move index for the next position
                count++;
            }
            movement->print();
        }
        ~knight() {
            delete movement;
        }
    private:
        int x, y, m, n, count;
        vector<vector<bool>> trace;
        Stack *movement;
        const int move[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
};

void main() {
    int n, x, y;
 /*   cout << "Enter the size of the chessboard (n): ";
    cin >> n;
    cout << "Enter the starting position of the knight (x y): ";
    cin >> x >> y;    */
    n = 5; // Example size
    x = 1; // Example starting x position
    y = 1; // Example starting y position
    // Validate input adjusting block
    if (n < 1) n = 1;
    if (x < 1) x = 1;
    if (x > n) x = n;
    if (y < 1) y = 1;
    if (y > n) y = n;
    // Create knight object and move it
    knight k(n, x, y);
    k.move_knight();
}