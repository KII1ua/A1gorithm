// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N;
int graph[17][17];
int dp[3][17][17];

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }
}

void solve() {
    dp[0][0][1] = 1;
    
    for(int i = 2; i < N; i++) {
        if(graph[0][i] != 1) {
            dp[0][0][i] = dp[0][0][i-1];
        }
    }

    for(int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++) {
            if(graph[i][j] == 0 && graph[i-1][j] == 0 && graph[i][j-1] == 0) {
                dp[1][i][j] = dp[0][i-1][j-1] + dp[1][i-1][j-1] + dp[2][i-1][j-1];
            }

            if(graph[i][j] == 0) {
                dp[0][i][j] = dp[0][i][j-1] + dp[1][i][j-1];
                dp[2][i][j] = dp[2][i-1][j] + dp[1][i-1][j];
            }
        }
    }

    int result = 0;
    for(int i = 0; i < 3; i++) {
        result += dp[i][N-1][N-1];
    }

    cout << result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
