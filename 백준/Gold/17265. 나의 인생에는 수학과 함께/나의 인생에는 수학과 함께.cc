#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

//int dx[] = {-1 ,1, 0, 0};
//int dy[] = {0, 0, -1, 1};
int dx[] = {1, 0};
int dy[] = {0, 1};
int N;
char graph[6][6];
int minresult = MAX;
int maxresult = -1e9;

void dfs(int x, int y, int tmp) {
    if(x == N-1 && y == N-1) {
        maxresult = max(maxresult, tmp);
        minresult = min(minresult, tmp);
        return;
    }

    for(int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int val = tmp;

        if(nx >= N || ny >= N) continue;

        if(graph[x][y] == '-') {
            val -= graph[nx][ny] - '0';
        }
        else if(graph[x][y] == '+') {
            val += graph[nx][ny] - '0';
        }
        else if(graph[x][y] == '*') {
            val *= graph[nx][ny] - '0';
        }
        dfs(nx, ny, val);
    }
}

void solve() {
    dfs(0, 0, graph[0][0] - '0');

    cout << maxresult << " " << minresult;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
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