#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int cycle(vector<int>& a, int n) {
    int res = 0;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }
        vis[i] = true;
        int j = a[i];
        while (j != i) {
            vis[j] = true;
            j = a[j];
        }
        res++;
    }
    return res;
}

void perm(vector<int>& a, int i, int n, int k, vector<vector<int>>& C,
          int& res) {
    if (i == n) {
        if (n - cycle(a, n) <= k) {
            int s = C[a[n - 1]][a[0]];
            for (int j = 1; j < n; j++) {
                s += C[a[j - 1]][a[j]];
            }
            res = max(res, s);
        }
        return;
    }
    for (int j = i; j < n; j++) {
        swap(a[i], a[j]);
        perm(a, i + 1, n, k, C, res);
        swap(a[i], a[j]);
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> C(N, vector<int>(N));
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> C[i][j];
        }
        a[i] = i;
    }
    int res = 0;
    perm(a, 0, N, K, C, res);
    cout << res << endl;
    return 0;
}