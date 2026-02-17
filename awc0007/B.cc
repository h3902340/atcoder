#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int mn = INT32_MAX;
    vector<vector<int>> w(N, vector<int>());
    unordered_map<string, int> mp;
    int idx = 0;
    for (int i = 0; i < N; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            string t;
            cin >> t;
            if (!mp.count(t)) {
                mp[t] = idx++;
            }
            w[i].push_back(mp[t]);
        }
    }
    for (int i = 0; i < N; i++) {
        sort(begin(w[i]), end(w[i]));
    }
    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int x = 0;
            int y = 0;
            int c = 0;
            while (x < w[i].size() && y < w[j].size()) {
                if (w[i][x] == w[j][y]) {
                    c++;
                    x++;
                    y++;
                } else if (w[i][x] < w[j][y]) {
                    x++;
                } else {
                    y++;
                }
            }
            if (c >= K) {
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}