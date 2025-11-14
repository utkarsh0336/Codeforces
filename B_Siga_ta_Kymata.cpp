/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;
    vector<int> p(n);
    int a = -1,b = -1;
    for(int i = 0;i < n; i++){
        int num;
        cin >> num;
        p[i] = num;
        if(num == 1) a = i;
        if(num == n) b = i;
    }

    string s;
    cin >> s;

    if(s[0] == '1' || s[n-1] == '1' || s[a] == '1' || s[b] == '1'){
        cout<<-1<<endl;
        return;
    }

    a++;
    b++;

    cout<<5<<endl;
    
    cout<<1<<" "<<a<<endl;
    cout<<1<<" "<<b<<endl;
    cout<<a<<" "<<n<<endl;
    cout<<b<<" "<<n<<endl;
    cout<<min(a,b)<<" "<<max(a,b)<<endl;
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
