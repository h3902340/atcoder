

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

#define ll long long
int mul(int a, int b, int p) { return (ll)a * b % p; }
int pow(int a, int b, int p) {
    if (a == 0) return 0;
    if (a == 1) return 1;
    if (b == 0) return 1;
    if (b & 1) {
        int temp = pow(a, b - 1, p);
        return mul(a, temp, p);
    }
    int temp = pow(a, b >> 1, p);
    return mul(temp, temp, p);
}
int inv(int a, int p) { return pow(a, p - 2, p); }
// TODO: time is O(M^2log(M)), can be improved to O(M^2) by building a state
// machine can start the known pairs that have M multiples
int main() {
    int m, a, b;
    cin >> m >> a >> b;
    vector<vector<int>> mp(m, vector<int>(m, -1));
    int res = m * m + 1;
    for (int i = 0; i < m; i++) {
        mp[i][0] = 0;
        mp[0][i] = 0;
        res -= 2;
    }
    unordered_set<int> se;
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < m; j++) {
            if (mp[i][j] != -1) {
                continue;
            }
            int s1 = i;
            int s2 = j;
            int v = m * s1 + s2;
            se.clear();
            do {
                mp[s1][s2] = 1;
                se.insert(v);
                s1 = (a * s2 + b * s1) % m;
                swap(s1, s2);
                if (mp[s1][s2] == 0) {
                    break;
                }
                v = m * s1 + s2;
            } while (!se.count(v));
            if (mp[s1][s2] == 0) {
                for (auto& e : se) {
                    mp[e / m][e % m] = 0;
                    res--;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}