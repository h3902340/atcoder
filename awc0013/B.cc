#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int N, M;
    cin >> N >> M;
    unordered_set<ll> se;
    int res = 0;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        ll v = ((ll)a << 32) | b;
        if (se.count(v)) {
            res++;
        } else {
            se.insert(v);
        }
    }
    cout << res << endl;
    return 0;
}