#include <iostream>
#include <vector>
using namespace std;

#define ll long long
ll solve(int n, int k, vector<int>& a) {
    ll res = 0;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i] + k) {
            res += a[i - 1] - a[i] - k;
            a[i] = a[i - 1] - k;
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        if (a[i - 1] + k < a[i]) {
            res += a[i] - a[i - 1] - k;
            a[i - 1] = a[i] - k;
        }
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll res = solve(n, k, a);
    cout << res << endl;
    return 0;
}