/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;

void Solve() {
    int n;
    long long s;
    cin >> n >> s;
    vector<pair<long long,int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i+1; // store 1-based index
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        long long target = s - arr[i].first;
        int l = i + 1, r = n - 1;
        while (l < r) {
            long long sum = arr[l].first + arr[r].first;
            if (sum == target) {
                cout << arr[i].second << " " << arr[l].second << " " << arr[r].second << "\n";
                return;
            }
            if (sum < target) l++;
            else r--;
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();
    return 0;
}
