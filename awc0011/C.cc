#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    ll N, K;
    cin >> N >> K;
    ll b = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        if ((a | K) != K) {
            continue;
        }
        b |= a;
        cnt++;
    }
    if (cnt > 0 && b == K) {
        cout << cnt << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}