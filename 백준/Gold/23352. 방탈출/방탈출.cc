// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, M;
int graph[51][51];
pair<int, int> result = {0, 0};

void bfs(int x, int y) {
    queue<tuple<int, int, int>> q;
    int visited[51][51];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visited[i][j] = 0;
        }
    }

    visited[x][y] = 1;
    q.push({x, y, 1});
    int mx = 0;

    while(!q.empty()) {
        int xx = get<0>(q.front());
        int yy = get<1>(q.front());
        int dist = get<2>(q.front());
        mx = max(mx, dist);
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if(nx >= 0 && ny >= 0 && nx < N && ny < M && graph[nx][ny] != 0) {
                if(!visited[nx][ny]) {
                    q.push({nx, ny, dist+1});
                    visited[nx][ny] = dist+1;
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(visited[i][j] == mx) {
                if(result.second < mx) {
                    result.first = graph[x][y] + graph[i][j];
                    result.second = mx;
                } else if(result.second == mx) {
                    result.first = max(result.first, graph[x][y] + graph[i][j]);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(graph[i][j] != 0) {
                bfs(i, j);
            }
        }
    }

    cout << result.first;
}
