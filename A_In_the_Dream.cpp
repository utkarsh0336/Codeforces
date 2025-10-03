#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a , b , c , d;
        cin >> a >> b >> c >> d;

        int maxi1 = max(a,b);
        int mini1 = min(a,b);

        int maxi2 = max(c-a,d-b);
        int mini2 = min(c-a,d-b);

        if(maxi1 - (2 * mini1) >= 3){
            cout<<"NO"<<endl;
            continue;
        }

        if(maxi2 - (2 * mini2) >= 3){
            cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;
    }
    return 0;
}
