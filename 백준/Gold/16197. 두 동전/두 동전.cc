#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
    int r;
};

struct halloween {
    int cnt;
    int score;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
char graph[22][22];
int answer = MAX;
pii a[2];


bool check(int x, int y) {
    if(x <= 0 || x > N || y <= 0 || y > M) return false;
    return true;
}

void dfs(int x, int y, int xx, int yy, int dir, int depth) {
    if(depth > 10) {
        return;
    }

    int nx = x + dx[dir];
    int ny = y + dy[dir];
    int nnx = xx + dx[dir];
    int nny = yy + dy[dir];

    if(check(nx, ny) ^ check(nnx, nny)) {
        answer = min(answer, depth);
        return;
    }
    else if(!check(nx, ny) && !check(nnx, nny)) {
        return;
    }

    if(graph[nx][ny] == '#') {
        nx = x;
        ny = y;
    }
    if(graph[nnx][nny] == '#') {
        nnx = xx;
        nny = yy;
    }

    for(int i = 0; i < 4; i++) {
        dfs(nx, ny, nnx, nny, i, depth+1);
    }
}

void solve() {
    for(int i = 0; i < 4; i++) {
        dfs(a[0].first, a[0].second, a[1].first, a[1].second, i, 1);
    }

    cout << ((answer == MAX)? -1: answer);
}

void input() {
    int cnt = 0;

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> graph[i][j];

            if(cnt == 0 && graph[i][j] == 'o') {
                a[cnt++] = {i, j};
            }
            else if(cnt == 1 && graph[i][j] == 'o') {
                a[cnt++] = {i, j};
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
