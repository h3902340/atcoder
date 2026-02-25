#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define ll long long
struct Pos {
    int i;
    int j;
};
int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N, string(M, 0));
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    vector<vector<int>> paths(N, vector<int>(M, -1));
    const int sz = N * M;
    vector<Pos> deque(sz);
    const int dirs[5]{0, 1, 0, -1, 0};
    int l = 0;
    int r = 0;
    deque[0] = {0, 0};
    paths[0][0] = 0;
    int cnt = 1;
    while (cnt > 0) {
        Pos t = deque[l++];
        if (l == sz) {
            l = 0;
        }
        cnt--;
        for (int i = 0; i < 4; i++) {
            int x = t.i + dirs[i];
            int y = t.j + dirs[i + 1];
            if (x < 0 || y < 0 || x >= N || y >= M) {
                continue;
            }
            if (paths[x][y] != -1) {
                continue;
            }
            if (S[x][y] == '.') {
                l--;
                if (l == -1) {
                    l += sz;
                }
                deque[l] = {x, y};
                paths[x][y] = paths[t.i][t.j];
            } else {
                r++;
                if (r == sz) {
                    r = 0;
                }
                deque[r] = {x, y};
                paths[x][y] = paths[t.i][t.j] + 1;
            }
            cnt++;
        }
    }
    cout << paths[N - 1][M - 1] << endl;
    return 0;
}