// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
ll dp[101][10];
int N;

void input() {
    cin >> N;
}

void solution() {
    ll result = 0;

    for(int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 0; j <= 9; j++) {
            if(j == 0) dp[i][j] = dp[i-1][j+1] % INF;
            else if(j == 9) dp[i][j] = dp[i-1][j-1] % INF;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1] % INF;
        }
    }

    for(int i = 0; i <= 9; i++) {
        result += dp[N][i] % INF;
    }

    cout << result % INF;
}

void solve() {
    input();
    solution();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();
}
