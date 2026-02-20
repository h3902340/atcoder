#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int N, K;
    cin >> N >> K;
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        pq.push(h);
    }
    ll res = 0;
    for (int i = 0; i < K; i++) {
        if (pq.empty()) {
            break;
        }
        pq.pop();
        res++;
    }
    while (!pq.empty()) {
        int t = pq.top();
        pq.pop();
        res += t;
    }
    cout << res << endl;
    return 0;
}