/* Utkarsh Sahay */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

void Solve() {
    int n;
    cin >> n;

    int m = 2 * n;
    vector<int> a(m);

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    vector<vector<int>> pos(n);

    for (int i = 0; i < m; i++) {
        pos[a[i]].push_back(i);
    }
    vector<int> pairSum(m);

    for (int i = 0; i < m; i++) {
        int x = a[i];
        pairSum[i] = pos[x][0] + pos[x][1];
    }

    vector<int> runStart(m);

    runStart[0] = 0;

    for (int i = 1; i < m; i++) {
        if (pairSum[i] == pairSum[i - 1]) {
            runStart[i] = runStart[i - 1];
        } else {
            runStart[i] = i;
        }
    }

    vector<int> seen(n + 1, 0);
    int timer = 0;
    int ans = 0;

    int maxC = 2 * m - 2;

    for (int C = 0; C <= maxC; C++) {
        timer++;
        bool hasElement = false;

        auto mark = [&](int x) {
            if (x >= 0 && x < n) {
                seen[x] = timer;
            }
        };

        if (C % 2 == 0) {
            int center = C / 2;

            if (center >= 0 && center < m) {
                mark(a[center]);
                hasElement = true;
            }
        }

        if (C >= 1) {
            int leftEnd = (C - 1) / 2;

            if (leftEnd >= 0 && leftEnd < m && pairSum[leftEnd] == C) {
                int leftStart = runStart[leftEnd];

                for (int i = leftStart; i <= leftEnd; i++) {
                    mark(a[i]);
                    hasElement = true;
                }
            }
        }

        if (hasElement) {
            int mex = 0;

            while (mex < n && seen[mex] == timer) {
                mex++;
            }

            ans = max(ans, mex);
        }
    }

    cout << ans << endl;
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