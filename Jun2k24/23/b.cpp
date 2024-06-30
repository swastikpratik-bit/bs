#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool stabilize(vector<vector<int>>& a) {
    int n = a.size();
    int m = a[0].size();
    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool isMax = true;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;
                    int ni = i + x;
                    int nj = j + y;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && a[ni][nj] >= a[i][j]) {
                        isMax = false;
                        break;
                    }
                }
                if (!isMax) break;
            }
            if (isMax) {
                a[i][j]--;
                found = true;
            }
        }
    }

    return found;
}

int main() {
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        while (stabilize(a)) {}

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}