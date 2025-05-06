#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int graph[250][250];
bool visited[250][250];
int R, C, gw, gv;       // 늑대, 양

/*
 *          빈 공간 :  0 : 울타리 : -1  : 늑대 : 1 양 : 2
 */

void bfs(int x, int y, int v, int k) {
    queue<pii> q;
    visited[x][y] = true;
    q.push(make_pair(x, y));
    int wolf = v, lamb = k;

    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if(nx >= 0 && nx < R && ny >= 0 && ny < C && graph[nx][ny] != -1) {
                if(!visited[nx][ny]) {
                    if(graph[nx][ny] == 1) {
                        wolf++;
                    }
                    else if(graph[nx][ny] == 2) {
                        lamb++;
                    }
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }

    if(lamb > wolf) {
        gv += lamb;
    }
    else gw += wolf;
}

void solve() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(!visited[i][j] && graph[i][j] != -1) {
                if(graph[i][j] == 1) {
                    bfs(i, j, 1, 0);
                }
                else if(graph[i][j] == 2) {
                    bfs(i, j, 0, 1);
                }
                else bfs(i, j, 0, 0);
            }
        }
    }

    cout << gv << " " << gw;
}

void input() {
    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            char tmp;
            cin >> tmp;

            if(tmp == '.') graph[i][j] = 0;
            else if(tmp == '#') graph[i][j] = -1;
            else if(tmp == 'v') graph[i][j] = 1;
            else graph[i][j] = 2;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}