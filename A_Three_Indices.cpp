/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

vector<int> NSL(vector<int> &a){
    stack<int> st;
    st.push(-1);
    vector<int> left(a.size());
    for(int i = 0;i < a.size(); i++){
        while(st.top() != -1 && a[st.top()] >= a[i]){
            st.pop();
        }
        left[i] = st.top();
        st.push(i);
    }
    return left;
}

vector<int> NSR(vector<int> &a){
    int n = a.size();
    stack<int> st;
    st.push(n);
    vector<int> right(n);
    for(int i = n-1;i >= 0; i--){
        while(st.top() != n && a[st.top()] >= a[i]){
            st.pop();
        }
        right[i] = st.top();
        st.push(i);
    }
    return right;
}
 
void Solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n; i++) cin >> a[i];

    int maxi = max_element(begin(a),end(a)) - begin(a) + 1;

    if(maxi != 1 && maxi != n){
        cout<<"YES"<<endl;
        cout<<maxi-1<<" "<<maxi<<" "<<maxi+1<<endl;
        return;
    }

    for(int i = 1;i < n-1; i++){
        if(a[i] > a[i-1] && a[i] > a[i+1]){
            cout<<"YES"<<endl;
            cout<<i<<" "<<i+1<<" "<<i+2<<endl;
            // cout<<maxi<<endl;
            return;
        }
    }

    vector<int> left = NSL(a);
    vector<int> right = NSR(a);

    for(int i = 1;i < n-1; i++){
        if(left[i] != -1 && right[i] != n){
            cout<<"YES"<<endl;
            cout<<left[i]+1<<" "<<i+1<<" "<<right[i]+1<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;
}
 
int main(){

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}