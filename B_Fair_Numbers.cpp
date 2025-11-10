/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isFair(int n){
    int num = n;
    while(num != 0){
        int dig = num % 10;

        if(dig != 0 && n % dig != 0){
            return false;
        }
        num /= 10;
    }
    return true;
}

void Solve(){
    int n;
    cin >> n;

    while(!isFair(n)){
        n += 1;
    }
    cout<<n<<endl;
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
