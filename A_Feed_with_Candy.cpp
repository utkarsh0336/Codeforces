/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;
#define int long long

int simulate(vector<pair<int,int>> c0, vector<pair<int,int>> c1, int x, int turn) {
    // sort by height
    sort(c0.begin(), c0.end());
    sort(c1.begin(), c1.end());

    priority_queue<int> pq0, pq1;
    int idx0 = 0, idx1 = 0, eaten = 0;

    while (true) {
        // push all reachable candies of each type into heap
        while (idx0 < (int)c0.size() && c0[idx0].first <= x) {
            pq0.push(c0[idx0].second);
            idx0++;
        }
        while (idx1 < (int)c1.size() && c1[idx1].first <= x) {
            pq1.push(c1[idx1].second);
            idx1++;
        }

        if (turn == 0) {
            if (pq0.empty()) break;
            x += pq0.top();
            pq0.pop();
        } else {
            if (pq1.empty()) break;
            x += pq1.top();
            pq1.pop();
        }
        eaten++;
        turn ^= 1; // alternate turn
    }

    return eaten;
}

void Solve() {
    int n, x;
    cin >> n >> x;

    vector<pair<int,int>> c0, c1; 
    for (int i = 0; i < n; i++) {
        int t, h, m;
        cin >> t >> h >> m;
        if (t == 0) c0.push_back({h, m});
        else c1.push_back({h, m});
    }

    int ans = max(simulate(c0, c1, x, 0), simulate(c0, c1, x, 1));
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        Solve();
    }

    return 0;
}
