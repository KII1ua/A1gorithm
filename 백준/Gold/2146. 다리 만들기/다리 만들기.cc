// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N;
int graph[101][101];
bool visited[101][101];

void divideisland(int x, int y, int cnt) {
    queue<pii> q;

    q.push(make_pair(x, y));
    visited[x][y] = true;
    graph[x][y] = cnt;

    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if(!visited[nx][ny] && graph[nx][ny] == -1) {
                    graph[nx][ny] = cnt;
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int bfs(int k) {
    queue<tuple<int, int, int>> q;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(graph[i][j] == k) {
                visited[i][j] = true;
                q.push(make_tuple(i, j, 0));
            }
        }
    }

    while(!q.empty()) {
        int xx = get<0>(q.front());
        int yy = get<1>(q.front());
        int dist = get<2>(q.front());
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if(graph[nx][ny] != 0 && !visited[nx][ny]) return dist;
                else if(graph[nx][ny] == 0 && !visited[nx][ny]) {
                    q.push(make_tuple(nx, ny, dist+1));
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int numlabel = 1;
    int answer = int(1e9);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 1) graph[i][j] = -1;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(graph[i][j] == -1) {
                divideisland(i, j, numlabel);
                numlabel++;
            }
        }
    }

    memset(visited, false, sizeof(visited));

    for(int i = 1; i < numlabel; i++) {
        answer = min(answer, bfs(i));
        memset(visited, false, sizeof(visited));
    }

    cout << answer;
}
