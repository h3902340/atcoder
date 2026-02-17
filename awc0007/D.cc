#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<vector<int>> b1(N + 1, vector<int>(N + 1));
    for (int i = 0; i < A; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        b1[r1 - 1][c1 - 1]++;
        b1[r1 - 1][c2]--;
        b1[r2][c1 - 1]--;
        b1[r2][c2]++;
    }
    vector<vector<int>> b2(N + 1, vector<int>(N + 1));
    for (int i = 0; i < B; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        b2[r1 - 1][c1 - 1]++;
        b2[r1 - 1][c2]--;
        b2[r2][c1 - 1]--;
        b2[r2][c2]++;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > 0) {
                b1[i][j] += b1[i - 1][j];
                b2[i][j] += b2[i - 1][j];
            }
            if (j > 0) {
                b1[i][j] += b1[i][j - 1];
                b2[i][j] += b2[i][j - 1];
            }
            if (i > 0 && j > 0) {
                b1[i][j] -= b1[i - 1][j - 1];
                b2[i][j] -= b2[i - 1][j - 1];
            }
        }
    }
    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (b1[i][j] > 0 && b2[i][j] > 0) {
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}