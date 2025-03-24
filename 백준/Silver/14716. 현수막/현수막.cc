#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, M;
int graph[251][251];
int cnt;

void bfs(int x, int y) {
    queue<pii> q;

    q.push(make_pair(x, y));
    graph[x][y] = 0;

    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(graph[nx][ny] == 1) {
                    q.push(make_pair(nx, ny));
                    graph[nx][ny] = 0;
                }
            }
        }
    }
}

void solution() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(graph[i][j] == 1) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
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
    solution();
}
