#include <iostream>
#include <vector>

using namespace std;

void solveAntiSudoku(vector<string>& grid) {
    for (int i = 0; i < 9; i++) {
        // Change one element in each row to create a duplicate
        // We can change the i-th element in the i-th row
        // This guarantees that each row will have at least two equal elements
        int changeIndex = (i % 3) * 3 + (i / 3); // Change within 3x3 block boundaries
        grid[i][changeIndex] = (grid[i][changeIndex] == '1') ? '2' : '1';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<string> grid(9);
        for (int i = 0; i < 9; i++) {
            cin >> grid[i];
        }
        
        solveAntiSudoku(grid);
        
        for (int i = 0; i < 9; i++) {
            cout << grid[i] << endl;
        }
    }
    return 0;
}
