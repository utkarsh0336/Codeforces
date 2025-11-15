/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

// void solve(int n,deque<int> &dq){
//     if(n == 4){
//        dq.push_back(3);
//        dq.push_back(1);
//        dq.push_back(4);
//        dq.push_back(2);
//        return;
//     }

//     solve(n-1,dq);

//     if(n % 2 == 0){
//         dq.push_back(n);
//     }
//     else{
//         dq.push_front(n);
//     }
// }

void Solve(){
    int n;
    cin >> n;

    if(n == 1){
        cout<<1<<endl;
        return;
    }
    if(n <= 3){
        cout<<"NO SOLUTION"<<endl;
        return;
    }
    deque<int> dq;
    // solve(n,dq);
    // while(!dq.empty()){
    //     cout<<dq.front()<<" ";
    //     dq.pop_front();
    // }
    // cout<<endl;
    dq.push_back(3);
    dq.push_back(1);
    dq.push_back(4);
    dq.push_back(2);

    for(int i = 5;i <= n; i++){
        if(i % 2 == 1) dq.push_front(i);
        else dq.push_back(i);
    }

    for(int x : dq) cout<<x<<" ";
    cout<<endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }

    return 0;
}
