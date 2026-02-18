#include <iostream>
#include <vector>
using namespace std;

#define ll long long
const int N = 2e5;
int tmp[N];
ll mergeSort(vector<int>& A, int l, int r) {
    if (l + 1 == r) {
        return 0;
    }
    int mid = (l + r) >> 1;
    ll a = mergeSort(A, l, mid);
    ll b = mergeSort(A, mid, r);
    int i = l;
    int j = mid;
    int k = 0;
    ll res = a + b;
    while (i < mid && j < r) {
        if (A[i] > A[j]) {
            res += j - k - l;
            tmp[k++] = A[j++];
        } else {
            tmp[k++] = A[i++];
        }
    }
    for (; i < mid; i++) {
        tmp[k++] = A[i];
    }
    for (; j < r; j++) {
        tmp[k++] = A[j];
    }
    for (int x = 0; x < k; x++) {
        A[l + x] = tmp[x];
    }
    return res;
}
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll res = mergeSort(A, 0, N);
    cout << res << endl;
    return 0;
}