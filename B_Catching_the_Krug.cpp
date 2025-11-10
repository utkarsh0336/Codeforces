/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
int n, rK, cK, rD, cD;
cin >> n >> rK >> cK >> rD >> cD;
int dr = rD - rK;
int dc = cD - cK;

auto check = [&](int k)->bool{
    int Lx = max(-k, -rK);
    int Rx = min(k, n - rK);

    int Ly = max(-k, -cK);
    int Ry = min(k, n - cK);

   
    long long maxRow = max( llabs((long long)Lx - dr), llabs((long long)Rx - dr) );
   
    long long maxCol = max( llabs((long long)Ly - dc), llabs((long long)Ry - dc) );

    long long worst = max(maxRow, maxCol);
    return worst <= k;
};

int lo = 0, hi = n;
while(lo < hi){
    int mid = (lo + hi) >> 1;
    if(check(mid)) hi = mid;
    else lo = mid + 1;
}
cout << lo << '\n';

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
