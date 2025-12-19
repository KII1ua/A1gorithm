#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
char graph[2001][2001];
int cost[2001][2001];
int visited[2001][2001];
int cycle[2001][2001];
int answer = 0;

int direct(char alpha) {
    if(alpha == 'U') return 3;
    else if(alpha == 'D') return 2;
    else if(alpha == 'L') return 1;
    else return 0;
}

void dfs(int x, int y) {
    int dir = direct(graph[x][y]);

    cycle[x][y] = 1;
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(nx < 0 || nx >= N || ny < 0 || ny >= M) {
        visited[x][y] = 1;
        return;
    }

    if(visited[nx][ny]) {
        visited[x][y] = 1;
        return;
    }

    if(cycle[nx][ny]) {
        int startx = x;
        int starty = y;
        int tmpcost = cost[x][y];

        int nextx = x + dx[dir];
        int nexty = y + dy[dir];

        while(startx != nextx || starty != nexty) {
            tmpcost = min(tmpcost, cost[nextx][nexty]);
            int nextdir = direct(graph[nextx][nexty]);
            nextx = nextx + dx[nextdir];
            nexty = nexty + dy[nextdir];
        }

        answer += tmpcost;
    }
    else {
        dfs(nx, ny);
    }
    
    visited[x][y] = 1;
}

void solve() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!cycle[i][j]) {
                dfs(i, j);
            }
        }
    }

    cout << answer;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> cost[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}