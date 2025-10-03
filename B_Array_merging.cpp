#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        unordered_map<int,int> maxA, maxB;

        // longest streaks in a
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && a[j] == a[i]) j++;
            maxA[a[i]] = max(maxA[a[i]], j - i);
            i = j;
        }
        // longest streaks in b
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && b[j] == b[i]) j++;
            maxB[b[i]] = max(maxB[b[i]], j - i);
            i = j;
        }

        int ans = 1;
        for (auto &[val, len] : maxA) {
            ans = max(ans, len + maxB[val]);
        }
        for (auto &[val, len] : maxB) {
            ans = max(ans, len + maxA[val]);
        }

        cout << ans << "\n";
    }
    return 0;
}
