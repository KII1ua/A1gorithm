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

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, M, cnt;
char Map[1001][1001];
int graph[1001][1001];
queue<pii> q;

bool check(int x, int y) {
    if(x >= 0 && x < N && y >= 0 && y < M) return true;
    else return false;
}

void bfs() {
    while(!q.empty()) {
        int sz = q.size();

        for(int i = 0; i < sz; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int j = 0; j < 8; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if(!check(nx, ny)) continue;

                if(graph[nx][ny] > 0) {
                    graph[nx][ny] -= 1;

                    if(graph[nx][ny] == 0) q.push({nx, ny});
                }
            }
        }
        cnt++;
    }
}

void solve() {
    bfs();

    cout << cnt - 1;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> Map[i][j];

            if(Map[i][j] == '.') {
                graph[i][j] = 0;
                q.push({i, j});
            }
            else graph[i][j] = Map[i][j] - '0';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
