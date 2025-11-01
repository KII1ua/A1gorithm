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

struct halloween {
    int cnt;
    int score;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M, startx, starty, endx, endy;
char graph[51][51];
pii visited[51][51];

bool check(int x, int y) {
    if(x < 0 || x >= N || y < 0 || y >= M) return false;
    return true;
}

void dijkstra() {
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
    pq.push({0, 0, startx, starty});
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visited[i][j].first = MAX;
            visited[i][j].second = MAX;
        }
    }
    visited[startx][starty] = {0, 0};

    while(!pq.empty()) {
        int garbage = get<0>(pq.top());
        int side = get<1>(pq.top());
        int x = get<2>(pq.top());
        int y = get<3>(pq.top());
        pq.pop();

        if(make_pair(garbage, side) > visited[x][y]) continue;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(!check(nx, ny)) continue;

            int ngarbage = garbage;
            int nside = side;

            if(graph[nx][ny] == 'g') ngarbage++;
            else if(graph[nx][ny] == '.'){
                bool isnear = false;

                for(int j = 0; j < 4; j++) {
                    int gx = nx + dx[j];
                    int gy = ny + dy[j];

                    if(check(gx, gy) && graph[gx][gy] == 'g') isnear = true;
                }
                if(isnear) nside++;
            }

            if(make_pair(ngarbage, nside) < visited[nx][ny]) {
                visited[nx][ny] = {ngarbage, nside};
                pq.push({ngarbage, nside, nx, ny});
            }
        }
    }
}

void solve() {
    dijkstra();

    cout << visited[endx][endy].first << " " << visited[endx][endy].second;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];

            if(graph[i][j] == 'S') startx = i, starty = j;

            if(graph[i][j] == 'F') endx = i, endy = j;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
