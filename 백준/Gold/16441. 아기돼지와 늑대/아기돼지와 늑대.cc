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

struct horse {
    int x;
    int y;
    int dir;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
char graph[101][101];
queue<pii> q;
bool visited[101][101];

void bfs() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if(graph[nx][ny] == '.' && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
            else {
                while(graph[nx][ny] != '.') {
                    if(graph[nx][ny] == '#') {      // 벽인 경우
                        nx -= dx[i];
                        ny -= dy[i];
                        break;
                    }
                    nx += dx[i];
                    ny += dy[i];
                }
                if(!visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

void Print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    bfs();

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(graph[i][j] != '.') {
                cout << graph[i][j];
            }
            else {
                if(!visited[i][j]) {
                    cout << "P";
                }
                else cout << graph[i][j];
            }
        }
        cout << endl;
    }
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];

            if(graph[i][j] == 'W') {
                q.push({i, j});
                visited[i][j] = true;
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
