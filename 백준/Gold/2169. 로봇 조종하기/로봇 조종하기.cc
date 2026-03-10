#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 200000;
const int D = 2000000;
const int MOD = 10007;
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};
int dx[] = {1, 0, 0};
int dy[] = {0, -1, 1};
int N, M;

int func(int x, int y, int dir, vector<vector<int>> &graph, vector<vector<vector<int>>> &dp) {
    if(x >= N || y >= M || x < 0 || y < 0) return -INF;

    if(x == N-1 && y == M-1) return graph[x][y];

    int &ret = dp[x][y][dir];

    if(ret != -1) return ret;

    ret = -INF;

    for(int i = 0; i < 3; i++) {
        if(dir == 1 && i == 2) continue;
        if(dir == 2 && i == 1) continue;

        int nx = x + dx[i];
        int ny = y + dy[i];

        ret = max(ret, func(nx, ny, i, graph, dp) + graph[x][y]);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    vector<vector<int>> v(N, vector<int>(M, 0));

    vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(3, -1)));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }

    cout << max({func(0, 0, 0, v, dp), func(0, 0, 1, v, dp), func(0, 0, 2, v, dp)});
}