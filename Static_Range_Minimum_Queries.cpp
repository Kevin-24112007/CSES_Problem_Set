//  Static Range Minimum Queries

#include<bits/stdc++.h>

using namespace std;

vector<int> tree;
const int INF = 1e9;

void build_st(vector<int>& a, int cur_idx, int left, int right) {
    if (left == right) {
        tree[cur_idx] = a[left];
    }
    else {
        int mid = left + (right - left) / 2;
        build_st(a, cur_idx*2, left, mid);
        build_st(a, cur_idx*2+1, mid+1, right);
        tree[cur_idx] = min(tree[cur_idx*2], tree[cur_idx*2+1]);
    }
}

int min_val(int idx, int left, int right, int l, int r) {
    if (l <= left && r >= right) {
        return tree[idx];
    }
    if (right < l || left > r) {
        return INF;
    }
    int mid = left + (right - left) / 2;
    return min(min_val(idx * 2, left, mid, l, r)
               ,min_val(idx * 2 + 1, mid + 1, right, l, r));
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int& n : a) cin >> n;
    tree.resize(N*4);
    build_st(a, 1, 0, N-1);
    while (Q--) {
        int a, b;
        cin >> a >> b;
        cout << min_val(1, 0, N-1, a-1, b-1) << endl;
    }
    return 0;
}
