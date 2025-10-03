/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;
#define int long long

// Encode (c,v) into a single 64-bit key
long long encode(long long c, long long v) {
    return (c << 32) ^ v;
}

void Solve() {
    int k, x;
    cin >> k >> x;

    long long tot = (1LL << k) + 1;   // total cakes = 2^k + 1
    long long c = (1LL << k);        // initial Chocola
    long long v = 1;                 // initial Vanilla
    long long tc = x;                // target Chocola
    long long tv = tot - x;          // target Vanilla

    if (c == tc && v == tv) {
        cout << 0 << "\n\n";
        return;
    }

    queue<pair<long long,long long>> q;
    unordered_map<long long, pair<long long,long long>> parent;
    unordered_set<long long> vis;

    q.push(make_pair(c,v));
    vis.insert(encode(c,v));

    pair<long long,long long> target = make_pair(-1,-1);

    while (!q.empty()) {
        pair<long long,long long> cur = q.front();
        q.pop();
        long long cc = cur.first;
        long long vv = cur.second;

        // operation 1: Chocola gives half if even
        if (cc % 2 == 0) {
            long long nc = cc/2;
            long long nv = vv + cc/2;
            long long key = encode(nc,nv);
            if (!vis.count(key)) {
                vis.insert(key);
                parent[key] = make_pair(encode(cc,vv), 1LL);
                if (nc == tc && nv == tv) {
                    target = make_pair(nc,nv);
                    break;
                }
                q.push(make_pair(nc,nv));
            }
        }

        // operation 2: Vanilla gives half if even
        if (vv % 2 == 0) {
            long long nc = cc + vv/2;
            long long nv = vv/2;
            long long key = encode(nc,nv);
            if (!vis.count(key)) {
                vis.insert(key);
                parent[key] = make_pair(encode(cc,vv), 2LL);
                if (nc == tc && nv == tv) {
                    target = make_pair(nc,nv);
                    break;
                }
                q.push(make_pair(nc,nv));
            }
        }
    }

    // reconstruct path
    vector<int> ops;
    long long curKey = encode(target.first, target.second);
    while (parent.count(curKey)) {
        pair<long long,long long> p = parent[curKey];
        ops.push_back((int)p.second);
        curKey = p.first;
    }
    reverse(ops.begin(), ops.end());

    cout << ops.size() << "\n";
    for (int i = 0; i < (int)ops.size(); i++) {
        cout << ops[i] << (i+1 == (int)ops.size() ? '\n' : ' ');
    }
    if (ops.empty()) cout << "\n";
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
