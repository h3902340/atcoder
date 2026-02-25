#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
int main() {
    int N, K, M;
    cin >> N >> K >> M;
    priority_queue<int> a;
    priority_queue<int> b;
    for (int i = 0; i < N; i++) {
        int h, p;
        cin >> h >> p;
        if (h == 0) {
            b.push(p);
        } else {
            a.push(p);
        }
    }
    if (a.size() < M || b.size() < K - M) {
        cout << -1 << endl;
    } else {
        ll res = 0;
        for (int i = 0; i < M; i++) {
            res += a.top();
            a.pop();
        }
        for (int i = 0; i < K - M; i++) {
            res += b.top();
            b.pop();
        }
        cout << res << endl;
    }
    return 0;
}