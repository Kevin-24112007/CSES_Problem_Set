//  Static Range Sum Queries

#include<bits/stdc++.h>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<long long> psum(N+1, 0);
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        psum[i] = num + psum[i - 1];
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << psum[r] - psum[l-1] << endl;
    }
    return 0;
}
