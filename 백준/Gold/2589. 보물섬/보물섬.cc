#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 20001;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int graph[51][51];
int dist[51][51];
int answer;
int N, M;

void bfs(int a, int b) {
    queue<pii> q;
    q.push({a, b});

    dist[a][b] = 0;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        answer = max(answer, dist[x][y]);
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if(dist[nx][ny] == -1 && graph[nx][ny] == 0) {
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
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
            char a;
            cin >> a;

            if(a == 'W') graph[i][j] = 1;
            else graph[i][j] = 0;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(graph[i][j] == 0) {
                memset(dist, -1, sizeof(dist));

                bfs(i, j);
            }
        }
    }

    cout << answer;
}