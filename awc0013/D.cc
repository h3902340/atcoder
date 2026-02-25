#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    vector<int> tmp(N);
    ll res = 0;
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            tmp[i] = A[i][j];
        }
        sort(begin(tmp), end(tmp));
        int l = 1;
        int r = N - 1;
        for (int i = 1; i < N; i++) {
            res += (ll)(tmp[i] - tmp[i - 1]) * l * r;
            l++;
            r--;
        }
    }
    cout << res << endl;
    return 0;
}