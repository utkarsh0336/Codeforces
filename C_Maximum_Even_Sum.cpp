#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        long long ans = 0;

        if(b % 2 == 0){
            ans = (a * b) / 2 + 2;
        }
        else{
            ans = a * b + 1;
        }


        if(ans % 2 == 1){
            cout<<-1<<endl;
            continue;
        }

        cout << ans << "\n";
    }
    return 0;
}
