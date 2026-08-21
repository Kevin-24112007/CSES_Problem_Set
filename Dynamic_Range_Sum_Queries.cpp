//  Dynamic Range Sum Queries

#include<bits/stdc++.h>

using namespace std;

vector<int> tree;

void build_st(vector<int>& x, int idx, int l_lim, int r_lim) {
    if (l_lim == r_lim) {
        tree[idx] = x[l_lim];
    }
    else {
        int mid = l_lim + (r_lim - l_lim) / 2;
        build_st(x, idx*2, l_lim, mid);
        build_st(x, idx*2+1, mid+1, r_lim);
        tree[idx] = tree[idx*2] + tree[idx*2+1];
    }
}

int find_sum(int idx, int l_lim, int r_lim, int l, int r) {
    if (l > r) return 0;
    if (l == l_lim && r == r_lim) return tree[idx];
    int mid = l_lim + (r_lim - l_lim) / 2;
    return find_sum(idx*2, l_lim, mid, l, min(r, mid)) +
        find_sum(idx*2+1, mid+1, r_lim, max(l, mid+1), r);
}

void update_st(int idx, int l_lim, int r_lim, int k, int val) {
    if (l_lim == r_lim) {
        tree[idx] = val;
    }
    else {
        int mid = l_lim + (r_lim - l_lim) / 2;
        if (k <= mid) update_st(idx*2, l_lim, mid, k, val);
        else update_st(idx*2+1, mid+1, r_lim, k, val);
        tree[idx] = tree[idx*2] + tree[idx*2+1];
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> x(N);
    for (int& n : x) cin >> n;
    int newN = 1;
    while (newN < N) {
        newN = newN<<1;
    }
    tree.resize(newN+newN);
    build_st(x, 1, 0, N-1);
    while (Q--) {
        int choice;
        cin >> choice;
        if (choice == 1) {
            int k, u;
            cin >> k >> u;
            update_st(1, 0, N-1, k-1, u);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << find_sum(1, 0, N-1, a-1, b-1) << endl;
        }
    }
    return 0;
}
