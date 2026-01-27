/* Utkarsh Sahay */

// Portable replacement for bits/stdc++.h
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <cmath>
#include <cstring>
#include <string>
#include <limits>
#include <climits>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int p = 31;

int power(int a,int b){
    int res = 1;
    while(b){
        if(b & 1){
            res *= a;
            res %= mod;
        }

        b /= 2;
        a *= a;
        a %= mod;
    }
    return res;
}

int inv(int a){
    return power(a,mod - 2);
}

int poly_hash_string(const string &s){
    int hash = 0;
    int p_pwr = 1;

    for(int i = 0;i < s.size(); i++){
        hash += (p_pwr * (s[i] - 'a' + 1));
        p_pwr *= p;
        p_pwr %= mod;
        hash %= mod;
    }

    return hash;
}

void Solve() {
    string text, pat;
    cin >> text >> pat;

    int n = text.size(), m = pat.size();
    if (m > n) return;

    int pat_hash = poly_hash_string(pat);
    int text_hash = poly_hash_string(text.substr(0, m));
    int p_m_1 = power(p, m - 1);

    if (pat_hash == text_hash) {
        cout << 0 << endl;
    }

    for (int i = 1; i + m <= n; i++) {
        int new_hash = text_hash;

        new_hash = (new_hash - (text[i - 1] - 'a' + 1) + mod) % mod;
        new_hash = (new_hash * inv(p)) % mod;
        new_hash = (new_hash + (text[i + m - 1] - 'a' + 1) * p_m_1) % mod;

        if (new_hash == pat_hash) {
            cout << i << endl;
        }

        text_hash = new_hash;
    }
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
