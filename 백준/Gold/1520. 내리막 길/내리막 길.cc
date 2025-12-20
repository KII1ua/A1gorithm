#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
int graph[501][501];
int dp[501][501];
int answer;

int func(int x, int y) {
    int &ret = dp[x][y];

    if(x == N-1 && y == M-1) {
        return 1;
    }

    if(ret != -1) return ret;

    ret = 0;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

        if(graph[nx][ny] < graph[x][y]) {
            ret += func(nx, ny);
        }
    }

    return ret;
}

void solve() {
    cout << func(0, 0);
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