#include <bits/stdc++.h>
using namespace std;

void solve(vector<long long>& arr) {
    sort(arr.begin(),arr.end());
    long long n = 1;
    for (long long num : arr) {
        if (n != num) {
            cout << n;
            return;
        }
        n++;
    }
    cout << n;
}

int main() {
	int N;
	cin >> N;
	N = N-1;
	vector<long long> arr(N);
	for (int i = 0; i < N; i++) {
	    cin >> arr[i];
	}
    solve(arr);
}
