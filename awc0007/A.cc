#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int N, M;
    cin >> N >> M;
    int mn = INT32_MAX;
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        mn = min(mn, e);
    }
    ll res = 0;
    for (int i = 0; i < M; i++) {
        int c;
        cin >> c;
        res += c;
    }
    res *= mn;
    cout << res << endl;
    return 0;
}