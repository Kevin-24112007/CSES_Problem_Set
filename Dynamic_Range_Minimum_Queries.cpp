//  Dynamic Range Minimum Queries

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

void update_st(int idx, int left, int right, int k, int val) {
    if (left == right) {
        tree[idx] = val;
    }
    else {
        int mid = left + (right - left) / 2;
        if (k <= mid) update_st(idx*2, left, mid, k, val);
        else update_st(idx*2+1, mid+1, right, k ,val);
        tree[idx] = min(tree[idx*2], tree[idx*2+1]);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int& n : a) cin >> n;
    int newN = 1;
    while (newN < N) {
        newN = newN << 1;
    }
    tree.resize(newN*2);
    build_st(a, 1, 0, N-1);
    while (Q--) {
        int choice;
        cin >> choice;
        if (choice == 2) {
            int a, b;
            cin >> a >> b;
            cout << min_val(1, 0, N-1, a-1, b-1) << endl;
        }
        else {
            int k, u;
            cin >> k >> u;
            update_st(1, 0, N-1, k-1, u);
        }
    }
    return 0;
}
