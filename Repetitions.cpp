#include <bits/stdc++.h>
using namespace std;

void solve(string s) {
    long long max_count = 1, curr_count = 1;
    for (int i = 1; i < s.size(); i++) {
        if(s[i] == s[i-1]) curr_count++;
        else {
            max_count = max(max_count,curr_count);
            curr_count = 1;
        }
    }
    cout << max(max_count,curr_count);
}

int main() {
	string str;
	getline(cin,str);
	solve(str);
}
