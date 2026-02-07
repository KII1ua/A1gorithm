#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 2e9;
const int MAX = 1001;
const int MOD = 1e9 + 7;
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};
int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};
int R, C, answer;
char graph[10001][501];
bool visited[10001][501];
bool flag;

void dfs(int x, int y) {
    visited[x][y] = true;

    if(y == C-1) {
        answer++;
        flag = true;
        return;
    }

    for(int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

        if(!visited[nx][ny] && graph[nx][ny] != 'x') {
            dfs(nx, ny);
            if(flag) return;
        }
    }
}

void solve() {
    for(int i = 0; i < R; i++) {
        flag = false;
        dfs(i, 0);
    }

    cout << answer;
}

void input() {
    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> graph[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}