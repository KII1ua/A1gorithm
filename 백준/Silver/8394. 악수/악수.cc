#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N;
int dp[10000001];

void solve() {
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= N; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10;
    }

    cout << dp[N];
}

void input() {
    cin >> N;
    solve();
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
