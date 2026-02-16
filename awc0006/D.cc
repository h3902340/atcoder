#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define ll long long
int main() {
    ll N, M;
    cin >> N >> M;
    map<int, int> mp;
    for (int i = 0; i < M; i++) {
        int L, R;
        cin >> L >> R;
        mp[L - 1] = max(mp[L - 1], R - 1);
    }
    int k = 0;
    int r = 0;
    auto it = mp.begin();
    while (r < N) {
        if (it == mp.end()) {
            k = -1;
            break;
        }
        int t = r;
        while ((*it).first <= t) {
            r = max(r, (*it).second + 1);
            it++;
            if (it == mp.end()) {
                break;
            }
        }
        if (t == r) {
            k = -1;
            break;
        }
        k++;
    }
    cout << k << endl;
    return 0;
}