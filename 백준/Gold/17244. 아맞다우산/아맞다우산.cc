#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M, Bit;
char graph[51][51];
bool visited[51][51][35];
pii start, End;

void bfs() {
    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(start.first, start.second, 0, 0));
    visited[start.first][start.second][0] = true;

    while(!q.empty()) {
        int xx = get<0>(q.front());
        int yy = get<1>(q.front());
        int cnt = get<2>(q.front());
        int state = get<3>(q.front());
        q.pop();

        if(graph[xx][yy] == 'E' && state == Bit) {
            cout << cnt;
            return;
        }

        for(int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            int bit_state = state;

            if(nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if('0' <= graph[nx][ny] && graph[nx][ny] < '5') {
                    bit_state = state | (1 << (graph[nx][ny] - '0'));
                    if(!visited[nx][ny][bit_state]) {
                        q.push(make_tuple(nx, ny, cnt+1, bit_state));
                        visited[nx][ny][bit_state] = true;
                    }
                }
                else if(graph[nx][ny] != '#') {
                    if(!visited[nx][ny][bit_state]) {
                        q.push(make_tuple(nx, ny, cnt+1, bit_state));
                        visited[nx][ny][bit_state] = true;
                    }
                }
            }
        }
    }
}

void input() {
    int idx = 0;
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 'S') {
                start.first = i;
                start.second = j;
            }
            else if(graph[i][j] == 'X') {
                graph[i][j] = (idx++) + '0';
            }
        }
    }
    Bit = (1 << idx) - 1;
}

void solve() {
    input();
    bfs();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();
}
