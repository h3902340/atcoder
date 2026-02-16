#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    ll N, M, D;
    cin >> N >> M >> D;
    ll res = 0;
    for (int i = 0; i < N; i++) {
        ll T;
        cin >> T;
        if (T <= M) {
            continue;
        }
        res += (T - M + D - 1) / D;
    }
    cout << res << endl;
    return 0;
}