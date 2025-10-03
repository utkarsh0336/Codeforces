/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
void Solve(){
    long long a,b;
    cin >> a >> b;
    
    if(a < b) swap(a,b);
    long long ans = a-b;
    if(ans == 0){
        cout<<0<<" "<<0<<endl;
        return;
    }

    cout<<ans<<" "<<min(b % ans,ans - b % ans)<<endl;

    

}
 
int main(){

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}