/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
void Solve(){
    string s;
    cin >> s;

    int n = s.size();

    int i = 0 , j = 0 , ans = 0;

    char ch = s[0];

    while(j < n){
        
        while(i < j && ch != s[j]){
            ans = max(ans,j-i);
            i++;
        }
        ch = s[j];
        j++;

    }
    ans = max(j-i,ans);

    cout<<ans;


}
 
int main(){

    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}