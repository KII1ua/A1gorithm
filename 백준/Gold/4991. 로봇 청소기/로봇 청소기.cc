#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M, Bit;
char graph[21][21];
bool visited[21][21][1050];
pii start;

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

        if(state == Bit) {
            cout << cnt << endl;
            return;
        }

        for(int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            int bit_state = state;

            if(nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if('0' <= graph[nx][ny] && graph[nx][ny] <= '9') {
                    bit_state |= 1 << (graph[nx][ny] - '0');

                    if(!visited[nx][ny][bit_state]) {
                        q.push(make_tuple(nx, ny, cnt+1, bit_state));
                        visited[nx][ny][bit_state] = true;
                    }
                }
                else if(graph[nx][ny] != 'x') {
                    if(!visited[nx][ny][bit_state]) {
                        q.push(make_tuple(nx, ny, cnt+1, bit_state));
                        visited[nx][ny][bit_state] = true;
                    }
                }
            }
        }
    }

    cout << -1 << endl;
    return;
}

void input() {
    while(true) {
        int idx = 0;
        cin >> N >> M;
        if(N == 0 && M == 0) return;

        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                cin >> graph[i][j];
                if(graph[i][j] == '*') {
                    graph[i][j] = (idx++) + '0';
                }
                else if(graph[i][j] == 'o') {
                    start.first = i;
                    start.second = j;
                }
            }
        }
        Bit = (1 << idx) - 1;

        memset(visited, 0, sizeof(visited));

        bfs();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
