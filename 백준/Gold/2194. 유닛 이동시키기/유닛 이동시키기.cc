#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const ll INF = 1e14 + 1;
const int MAX = 502;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M, A, B, K;
int graph[MAX][MAX];
bool visited[MAX][MAX];
int startx, starty, endx, endy;

bool check(int x, int y) {
    for(int i = x; i < x + A; i++) {
        for(int j = y; j < y + B; j++) {
            if(graph[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

void bfs() {
    queue<tuple<int, int, int>> q;
    if(check(startx, starty) && !visited[startx][starty]) {
        q.push({startx, starty, 0});
        visited[startx][starty] = true;
    }

    while(!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        q.pop();

        if(x == endx && y == endy) {
            cout << cnt;
            exit(0);
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <= 0 || nx + A - 1 > N || ny <= 0 || ny + B - 1 > M) continue;

            if(check(nx, ny) && !visited[nx][ny]) {
                q.push({nx, ny, cnt+1});
                visited[nx][ny] = true;
            }
        }
    }
}

void solve() {
    bfs();

    cout << -1;
}

void input() {
    cin >> N >> M >> A >> B >> K;

    for(int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }

    cin >> startx >> starty >> endx >> endy;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}