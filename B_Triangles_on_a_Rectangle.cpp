/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int w,h;
    cin >> w >> h;

    int x1max = -1, x2max = -1;
    for(int i = 0;i < 2; i++){
        int k;
        cin >> k;
        int maxi = -1,mini = INT_MAX;
        for(int j = 0;j < k; j++){
            int x;
            cin >> x;
            maxi = max(maxi,x);
            mini = min(mini,x);
        }
        if(i == 0){
            x1max = max(x1max,maxi - mini);
        }
        if(i == 1){
            x2max = max(x2max,maxi - mini);
        }

    }


    int y1max = -1, y2max = -1;
    for(int i = 0;i < 2; i++){
        int k;
        cin >> k;
        int maxi = -1,mini = INT_MAX;
        for(int j = 0;j < k; j++){
            int y;
            cin >> y;
            maxi = max(maxi,y);
            mini = min(mini,y);
        }
        if(i == 0){
            y1max = max(y1max,maxi - mini);
        }
        if(i == 1){
            y2max = max(y2max,maxi - mini);
        }
    }

    int ans = max({x1max * h , x2max * h , y1max * w , y2max * w});
    cout<<ans<<endl;

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
