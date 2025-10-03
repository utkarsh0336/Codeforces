/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

void Solve() {
    int n;
    cin >> n;

    int num = n;
    int cnt2 = 0, cnt3 = 0;

    while(num % 2 == 0){
        cnt2++;
        num /= 2;
    }
    while(num % 3 == 0){
        cnt3++;
        num /= 3;
    }

    // If leftover factor remains (not 1), invalid
    if(num != 1){
        cout << -1 << endl;
        return;
    }

    if(cnt2 > cnt3){
        cout << -1 << endl;
        return;
    }

    cout << 2 * cnt3 - cnt2 << endl;
}
 
int main() {
    ios::sync_with_stdio(false); // fast I/O
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
    return 0;
}
