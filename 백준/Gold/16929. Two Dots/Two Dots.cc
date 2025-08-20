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

int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};
int N, M;
char graph[51][51];
bool visited[51][51];
bool flag = false;

void dfs(int x, int y, int dir, int cnt, int startx, int starty) {
    if(flag) return;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if(!visited[nx][ny]) {      // 방문하지 않은 경우
                if(graph[x][y] == graph[nx][ny]) {
                    visited[nx][ny] = true;
                    if(i == dir) {      // 방향이 같은 경우
                        dfs(nx, ny, dir, cnt, startx, starty);
                    }
                    else dfs(nx, ny, i, cnt+1, startx, starty);
                }
            }
            else {
                if(nx == startx && ny == starty && cnt >= 4) {
                    flag = true;
                    return;
                }
            }
        }
    }
}

void solve() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            for(int k = 0; k < 4; k++) {
                memset(visited, 0, sizeof(visited));
                visited[i][j] = true;
                dfs(i, j, k, 1, i, j);
                if(flag) {
                    cout << "Yes";
                    return;
                }
            }
        }
    }

    cout << "No";
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
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
