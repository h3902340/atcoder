

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int l = 1;
        if (mp.count(a[i] - 1)) {
            l += mp[a[i] - 1];
        }
        mp[a[i]] = max(mp[a[i]], l);
    }
    int res = 0;
    for (auto& e : mp) {
        res = max(res, e.second);
    }
    cout << res << endl;
    return 0;
}