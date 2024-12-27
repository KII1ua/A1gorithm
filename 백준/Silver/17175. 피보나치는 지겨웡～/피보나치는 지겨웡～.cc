#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n";

bool compare(string a, string b) {
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    ll dp[51] = {0};

    dp[0] = 1;
    dp[1] = 1;

    cin >> N;

    for(int i = 2; i < 51; i++) {
        dp[i] = dp[i-1] + dp[i-2] + 1;
    }
    cout << dp[N] % 1000000007;
}