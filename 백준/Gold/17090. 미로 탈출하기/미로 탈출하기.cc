#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e11

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int N, M;
char graph[501][501];
int dp[501][501];

int dfs(int x, int y) {
    if(x < 0 || x >= N || y < 0 || y >= M) return 1;
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;

    int dirx = 0;
    int diry = 0;

    if(graph[x][y] == 'U') dirx = -1;
    else if(graph[x][y] == 'R') diry = 1;
    else if(graph[x][y] == 'D') dirx = 1;
    else diry = -1;

    dp[x][y] = dfs(x + dirx, y + diry);

    return dp[x][y];
}

void solve() {
    int result = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            result += dfs(i, j);
        }
    }

    cout << result;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];
            dp[i][j] = -1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}