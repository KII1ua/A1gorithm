// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
ll dp[118];
int N;

void solve() {
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for(int i = 4; i <= N; i++) {
        dp[i] = dp[i-1] + dp[i-3];
    }

    cout << dp[N];
}

void input() {
    cin >> N;
}

void solution() {
    input();
    solve();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solution();
}
