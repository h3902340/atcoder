#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define ll long long
int main() {
    ll N, M;
    cin >> N >> M;
    map<ll, int> mp;
    for (int i = 0; i < M; i++) {
        ll l, r;
        cin >> l >> r;
        mp[l]++;
        mp[r + 1]--;
    }
    ll day = 1;
    int rain = 0;
    for (auto& e : mp) {
        if (rain == 0) {
            ll diff = e.first - day;
            if (N <= diff) {
                day += N - 1;
                N = 0;
                break;
            }
            N -= diff;
        }
        rain += e.second;
        day = e.first;
    }
    if (N > 0) {
        day += N - 1;
    }
    cout << day << endl;
    return 0;
}