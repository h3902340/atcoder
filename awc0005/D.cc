#include <iostream>
#include <vector>
using namespace std;

#define ll long long
ll solve(int n, int k, vector<int>& a) {
    ll l = 1;
    ll r = 0;
    for (int i = 0; i < n; i++) {
        r += a[i];
    }
    ll res = 0;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        ll w = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            w += a[i];
            if (w >= mid) {
                w = 0;
                cnt++;
            }
        }
        if (cnt > k) {
            res = mid;
            l = mid + 1;
        } else if (cnt < k) {
            r = mid - 1;
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