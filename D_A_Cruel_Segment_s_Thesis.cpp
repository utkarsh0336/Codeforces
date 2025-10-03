/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;
    vector<int> L(n), R(n);
    int l, r;
    int base_sum = 0; // sum of original lengths
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        L[i] = l;
        R[i] = r;
        base_sum += (r - l);
    }

    sort(L.begin(), L.end());                   // ascending l
    sort(R.begin(), R.end(), greater<int>());   // descending r

    int k = n / 2;
    int extra = 0;
    for (int i = 0; i < k; ++i) {
        int gain = R[i] - L[i];
        if (gain > 0) extra += gain;
    }

    cout << (base_sum + extra) << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        Solve();
    }

    return 0;
}
