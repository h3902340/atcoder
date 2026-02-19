#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    ll N, S, C;
    cin >> N >> S >> C;
    ll res = 0;
    for (int i = 0; i < N; i++) {
        int h, p;
        cin >> h >> p;
        if (S < h) {
            res += C;
        } else {
            S += p - h;
        }
    }
    cout << res << endl;
    return 0;
}