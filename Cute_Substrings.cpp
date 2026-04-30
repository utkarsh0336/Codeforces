/* Utkarsh Sahay */

// Portable replacement for bits/stdc++.h
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <cmath>
#include <cstring>
#include <string>
#include <limits>
#include <climits>

using namespace std;

#define int long long

int solve(string &s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int len = j - i + 1;

                // cute string length must be odd
                if (len % 2 == 0) continue;

                bool ok = true;

                for (int k = i; k <= j; k++) {
                    int pos = k - i; // position inside substring, 0-based

                    if (pos % 2 == 0) {
                        // 1st, 3rd, 5th... character
                        if (s[k] != 'u' && s[k] != 'o') {
                            ok = false;
                            break;
                        }
                    } else {
                        // 2nd, 4th, 6th... character
                        if (s[k] != 'w') {
                            ok = false;
                            break;
                        }
                    }
                }

                if (ok) {
                    ans = max(ans, len);
                }
            }
        }

        return ans;
    }

void Solve() {
    // your logic
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = solve(s);

    cout<<ans<<endl;
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
