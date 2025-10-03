/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;

void Solve() {
    long long n;
    cin >> n;

    if((n & (n-1)) == 0){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }

    return 0;
}
