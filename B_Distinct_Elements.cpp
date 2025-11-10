#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<int> a(n);
        vector<int> used_numbers;
        int next_number = 1;
        long long prev = 0;

        for (int i = 0; i < n; i++) {
            long long d = b[i] - prev;
            prev = b[i];

            if (d > 0) {
                // introduce a new number
                a[i] = next_number;
                used_numbers.push_back(next_number);
                next_number++;
            } else {
                // reuse any previously used number
                a[i] = used_numbers[0]; // always reuse the first one
            }
        }

        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}
