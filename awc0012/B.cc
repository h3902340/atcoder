#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int N, T, C, D;
    cin >> N >> T >> C >> D;
    ll res = 0;
    C = min(C, D);
    for (int i = 0; i < N; i++) {
        int w;
        cin >> w;
        if (w >= T) {
            res += C;
        }
    }
    cout << res << endl;
    return 0;
}