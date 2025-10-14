#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e10

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
int N, K, R;
int graph[102][102][4];
vector<pii> v;
bool visited[102][102];

int changeDir(int a) {
    if(a == 0) return 1;
    if(a == 1) return 0;
    if(a == 2) return 3;
    if(a == 3) return 2;

    return 0;
}

void bfs(int a, int b) {
    queue<pii> q;
    q.push({a, b});
    visited[a][b] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            if(graph[x][y][i]) continue;
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <= 0 || nx > N || ny <= 0 || ny > N) continue;

            if(!visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

void solve() {
    int answer = 0;

    for(int i = 0; i < K; i++) {
        memset(visited, 0, sizeof(visited));
        bfs(v[i].first, v[i].second);

        for(int j = i+1; j < K; j++) {
            if(!visited[v[j].first][v[j].second]) {
                answer++;
            }
        }
    }

    cout << answer;
}

void input() {
    cin >> N >> K >> R;

    for(int i = 0; i < R; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for(int j = 0; j < 4; j++) {
            int nx = a + dx[j];
            int ny = b + dy[j];

            if(c == nx && d == ny) {
                graph[a][b][j] = 1;
                int dir = changeDir(j);
                graph[c][d][dir] = 1;
            }
        }
    }

    for(int i = 0; i < R; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
