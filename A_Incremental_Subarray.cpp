#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    bool flg = false;
    for(int i = m-1;i > 0; i--){
        if(a[i] == 1){
            flg = true;
            break;
        }
    }
    if(flg){
        cout<<1<<endl;
        return;
    }

    cout<<n - a[m-1] + 1<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) Solve();
    return 0;
}
