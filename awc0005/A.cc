#include <iostream>
#include <vector>
using namespace std;

#define ll long long
ll solve(int n, int k, vector<int>& p) {
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] % k == 0) {
            res += p[i];
        }
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    ll res = solve(n, k, p);
    cout << res << endl;
    return 0;
}