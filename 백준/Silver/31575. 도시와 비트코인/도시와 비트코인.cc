#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e8

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int N, M;
int graph[301][301];
bool visited[301][301];

bool check(int x, int y) {
    if(x >= 0 && x < M && y >= 0 && y < N) return true;
    return false;
}

void dfs(int x, int y) {
    if(x == M-1 && y == N-1) {
        cout << "Yes";
        exit(0);
    }
    visited[x][y] = true;

    for(int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(check(nx, ny) && !visited[nx][ny] && graph[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}

void solve() {
    dfs(0, 0);

    cout << "No";
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
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