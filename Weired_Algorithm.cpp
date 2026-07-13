#include <bits/stdc++.h>
using namespace std;

vector<long long> ans;
void solve(long long num) {
    ans.push_back(num);
    if(num == 1){
        for(size_t i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
    }
    else if(num%2 == 0) solve(num/2);
    else solve(num*3 + 1);
}

int main() {
    long long n;
    cin >> n;
    solve(n);
}