#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 51;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M, startx, starty;
char graph[MAX][MAX];
bool visited[MAX][MAX][66];

void bfs() {
    queue<tuple<int, int, int, int>> q;
    q.push({startx, starty, 0, 0});
    visited[startx][starty][0] = true;

    while(!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        int state = get<3>(q.front());
        q.pop();

        if(graph[x][y] == '1') {
            cout << cnt;
            exit(0);
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int status = state;

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if(graph[nx][ny] == '#') continue;

            if(graph[nx][ny] - 'a' >= 0 && graph[nx][ny] - 'a' < 6) {     // 열쇠인 경우
                status |= 1 << (graph[nx][ny] - 'a');

                if(!visited[nx][ny][status]) {
                    q.push({nx, ny, cnt+1, status});
                    visited[nx][ny][status] = true;
                    continue;
                }
            }
            else if(graph[nx][ny] - 'A' >= 0 && graph[nx][ny] - 'A' < 6) {      // 문인 경우
                int key = graph[nx][ny] - 'A';

                if((1 << key) & status && !visited[nx][ny][status]) {
                    q.push({nx, ny, cnt+1, status});
                    visited[nx][ny][status] = true;
                    continue;
                }
            }
            else {
                if(!visited[nx][ny][status]) {
                    q.push({nx, ny, cnt+1, status});
                    visited[nx][ny][status] = true;
                }
            }

        }
    }
}

void solve() {
    bfs();

    cout << -1;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];

            if(graph[i][j] == '0') {
                startx = i;
                starty = j;
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