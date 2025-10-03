/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void Solve(){
    int n;
    cin >> n;


    vector<int> mini,secmini;
    int minimum = INT_MAX;
    for(int i = 0;i < n; i++){
        int m;
        cin >> m;
        mini.resize(n);
        secmini.resize(n);
        int minmum = INT_MAX;
        int secminimum = INT_MAX;
        int num;
        for(int j = 0; j < m; j++){
            cin >> num;
            if(minmum >= num){
                secminimum = minmum;
                minmum = num;
            }
            else{
                secminimum = min(secminimum,num);
            }
        }
        minimum = min(minimum,minmum);
        mini[i] = minmum;
        secmini[i] = secminimum;
    }

    // for(auto m : mini) cout<<m<<" ";
    // cout<<endl;
    // for(auto m : secmini) cout<<m<<" ";
    
    int idx = min_element(begin(secmini),end(secmini)) - begin(secmini);
    int sum_second = 0;
    for(int i = 0;i < secmini.size(); i++){
      if(i != idx) sum_second += secmini[i];
    }
    sum_second += min(minimum,mini[idx]);
    cout<<sum_second<<endl;

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