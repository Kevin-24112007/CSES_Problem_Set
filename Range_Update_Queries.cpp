//  Range Update Queries

#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> tree;

void update(int idx, int left, int right, int l, int r, int val) {
    if (l > right || r < left) {
        return;
    }
    if (l <= left && r >= right) {
        tree[idx] += val;
        return;
    }
    else {
        int mid = (left + right) / 2;
        update(idx*2, left, mid, l, r, val);
        update(idx*2+1, mid+1, right, l , r, val);
    }
}

ll find(vector<int>& x, int idx, int left, int right, int l, int r) {
    if (r < left || l > right) {
        return 0;
    }
    if (l <= left && r >= right) {
        return tree[idx];
    }
    int mid = left + (right - left) / 2;
    return tree[idx] + find(x, idx*2, left, mid, l, r) + find(x, idx*2+1, mid+1, right, l, r);
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> x(N);
    for (int& n : x) cin >> n;
    int newN = 1;
    while (N > newN) {
        newN = newN << 1;
    }
    tree.resize(newN*2, 0);
    while (Q--) {
        int choice;
        cin >> choice;
        if (choice == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            update(1, 0, N-1, a-1, b-1, u);
        }
        else {
            int k;
            cin >> k;
            cout << x[k-1] + find(x, 1, 0, N-1, k-1, k-1) << endl;
        }
    }
    return 0;
}
