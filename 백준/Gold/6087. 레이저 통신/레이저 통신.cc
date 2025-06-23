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

int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int W, H;
int graph[101][101];
int startx, starty, endx, endy, tmp;
int visited[101][101][4];

/*
 *  0 -> 빈칸
 *  1 -> 시작점
 *  -1 -> 장애물
 */


void bfs(int a, int b) {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            for(int k = 0; k < 4; k++) {
                visited[i][j][k] = MAX;
            }
        }
    }
    queue<tuple<int, int, int, int>> q;     // 거울 횟수, 방향, 좌표
    for(int i = 0; i < 4; i++) {
        q.push({0, i, a, b});
        visited[a][b][i] = 0;
    }

    while(!q.empty()) {
        int cnt = get<0>(q.front());
        int dir = get<1>(q.front());
        int x = get<2>(q.front());
        int y = get<3>(q.front());
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ncnt = cnt;

            if(nx >= H || nx < 0 || ny >= W || ny < 0) continue;
            if(graph[nx][ny] == -1) continue;
            if(dir != i) ncnt = cnt + 1;

            if(visited[nx][ny][i] > ncnt) {
                visited[nx][ny][i] = ncnt;
                q.push({ncnt, i, nx, ny});
            }
        }
    }
}

void solve() {
    bfs(startx, starty);

    int result = MAX;
    for(int i = 0; i < 4; i++) {
        result = min(visited[endx][endy][i], result);
    }

    cout << result;
}

void input() {
    cin >> W >> H;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            char a;
            cin >> a;

            if(a == '.') graph[i][j] = 0;
            else if(a == '*') graph[i][j] = -1;
            else {
                graph[i][j] = 1;
                if(tmp == 0) {
                    startx = i;
                    starty = j;
                }
                else {
                    endx = i;
                    endy = j;
                }
                tmp++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}