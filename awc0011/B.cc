#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int H, W, K;
    char c1, c2;
    cin >> H >> W >> K;
    cin >> c1 >> c2;
    vector<string> ori(H, string(W, 0));
    for (int i = 0; i < H; i++) {
        cin >> ori[i];
    }
    vector<string> res(H * K, string(W * K, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 0; k < K; k++) {
                for (int l = 0; l < K; l++) {
                    res[i * K + k][j * K + l] = ori[i][j] == '#' ? c1 : c2;
                }
            }
        }
    }
    for (int i = 0; i < H * K; i++) {
        cout << res[i] << endl;
    }
    return 0;
}