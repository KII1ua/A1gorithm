#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e8

struct coordinate {
    int x;
    int y;
};

//int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
//int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int dx[] = {-3, -3, -2, -2, 2, 2, 3, 3};
int dy[] = {-2, 2, -3, 3, -3, 3, -2, 2};
int a, b, c, d;
int graph[10][10];
bool visited[10][10];

bool check(int x, int y, int way) {
    int Dx[8][2] = {
            {-1, -2},
            {-1, -2},
            {0, -1},
            {0, -1},
            {0, 1},
            {0, 1},
            {1, 2},
            {1, 2}
    };
    int Dy[8][2] = {
            {0, -1},
            {0, 1},
            {-1, -2},
            {1, 2},
            {-1, -2},
            {1, 2},
            {0, -1},
            {0, 1}
    };

    for(int i = 0; i < 2; i++) {
        int nx = x + Dx[way][i];
        int ny = y + Dy[way][i];

        if(graph[nx][ny] == 1) return false;
    }
    return true;
}

void bfs(int x, int y) {
    queue<tuple<int, int, int>> q;
    visited[x][y] = true;
    q.push({x, y, 0});

    while(!q.empty()) {
        int xx = get<0>(q.front());
        int yy = get<1>(q.front());
        int cnt = get<2>(q.front());
        q.pop();

        if(graph[xx][yy] == 1) {
            cout << cnt;
            exit(0);
        }

        for(int i = 0; i < 8; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if(check(xx, yy, i)) {
                if (nx >= 0 && nx <= 9 && ny >= 0 && ny <= 8) {
                    if (!visited[nx][ny]) {
                        q.push({nx, ny, cnt + 1});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }
}

void solve() {
    bfs(a, b);

    cout << -1;
}

void input() {
    cin >> a >> b >> c >> d;

    graph[a][b] = 2;        // 상
    graph[c][d] = 1;        // 왕
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}