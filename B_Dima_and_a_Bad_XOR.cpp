#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    vector<int> pick(n, 1);
    int xor_sum = 0;
    for (int i = 0; i < n; i++)
        xor_sum ^= a[i][0];

    if (xor_sum > 0) {
        cout << "TAK\n";
        for (int i = 0; i < n; i++) cout << pick[i] << " ";
        cout << "\n";
        return 0;
    }

    // Try to make xor_sum > 0 by changing one pick
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] != a[i][0]) {
                pick[i] = j + 1; // 1-based indexing
                cout << "TAK\n";
                for (int k = 0; k < n; k++) cout << pick[k] << " ";
                cout << "\n";
                return 0;
            }
        }
    }

    cout << "NIE\n";
}
