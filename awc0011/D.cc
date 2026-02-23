#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5;
vector<int> adj[N];
int lev[N];

#define ll long long
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> V(N);
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
        adj[i].clear();
    }
    P[0] = -1;
    for (int i = 1; i < N; i++) {
        cin >> P[i];
    }
    for (int i = 1; i < N; i++) {
        int u = i;
        int v = P[i] - 1;
        adj[v].push_back(u);
    }
    int l = 0;
    int r = 1;
    lev[0] = 0;
    while (l < r) {
        int u = lev[l++];
        for (auto& v : adj[u]) {
            lev[r++] = v;
            V[v] += V[u];
        }
    }
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        cout << V[x - 1] << endl;
    }
    return 0;
}