#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define ll long long
struct Data {
    int f;
    int d;
    bool operator<(const Data& a) const { return f < a.f; }
    bool operator>(const Data& a) const { return f > a.f; }
};
int main() {
    int N, M;
    cin >> N >> M;
    ll res = 0;
    priority_queue<Data> pq;
    for (int i = 0; i < N; i++) {
        int f, d;
        cin >> f >> d;
        pq.push({f, d});
    }
    while (M-- && !pq.empty()) {
        Data t = pq.top();
        pq.pop();
        res += t.f;
        t.f = max(t.f - t.d, 0);
        if (t.f > 0) {
            pq.push(t);
        }
    }
    cout << res << endl;
    return 0;
}