/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;

void Solve() {
    string s;
    cin >> s;

    unordered_map<char, int> mp;
    for (char ch : s) {
        mp[ch]++;
    }

    int oddcnt = 0;
    char oddChar = 0;

    // Count odd frequencies and store the odd char if any
    for (auto &it : mp) {
        if (it.second % 2 == 1) {
            oddcnt++;
            oddChar = it.first;
        }
    }

    // More than 1 odd char → not possible
    if (oddcnt > 1) {
        cout << "NO SOLUTION\n";
        return;
    }

    string half = "";

    // Build half of the palindrome
    for (auto &it : mp) {
        half += string(it.second / 2, it.first); // freq/2 copies of char
    }

    // Create second half by reversing
    string secondHalf = half;
    reverse(secondHalf.begin(), secondHalf.end());

    // If odd char exists, place it in the middle
    string ans;
    if (oddcnt == 1) {
        ans = half + string(1, oddChar) + secondHalf;
    } else {
        ans = half + secondHalf;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        Solve();
    }

    return 0;
}
