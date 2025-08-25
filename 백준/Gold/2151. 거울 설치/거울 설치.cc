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
int N;
char graph[51][51];
vector<pii> start;      // 0 시작 , 1 도착
int dist[51][51][4];
int cnt;

void Init() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < 4; k++) {
                dist[i][j][k] = MAX;
            }
        }
    }
}

int turn(int dir, char mirror) {
    if(mirror == '/') {
        if(dir == 0) return 3;
        if(dir == 1) return 2;
        if(dir == 2) return 1;
        else return 0;
    }
    else {
        if(dir == 0) return 2;
        if(dir == 1) return 3;
        if(dir == 2) return 0;
        else return 1;
    }
}

void dijkstra(int startx, int starty) {
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
    Init();
    for(int i = 0; i < 4; i++) {
        pq.push({0, i, startx, starty});
        dist[startx][starty][i] = 0;
    }

    while(!pq.empty()) {
        int x = get<2>(pq.top());
        int y = get<3>(pq.top());
        int cost = get<0>(pq.top());
        int dir = get<1>(pq.top());
        pq.pop();

        if(dist[x][y][dir] < cost) continue;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

        if(graph[nx][ny] == '*') continue;

        if(graph[nx][ny] == '.' || graph[nx][ny] == '#') {
            if(dist[nx][ny][dir] > cost) {
                pq.push({cost, dir, nx, ny});
                dist[nx][ny][dir] = cost;
            }
        }
        else if(graph[nx][ny] == '!') {
            int dirs = turn(dir, '/');

            if(dist[nx][ny][dir] > cost) {
                pq.push({cost, dir, nx, ny});
                dist[nx][ny][dir] = cost;
            }

            if(dist[nx][ny][dirs] > cost+1) {
                pq.push({cost+1, dirs, nx, ny});
                dist[nx][ny][dirs] = cost+1;
            }

            dirs = turn(dir, '\\');

            if(dist[nx][ny][dirs] > cost + 1) {
                pq.push({cost+1, dirs, nx, ny});
                dist[nx][ny][dirs] = cost + 1;
            }
        }
    }
}

void solve() {
    dijkstra(start[0].first, start[0].second);

    int answer = MAX;

    for(int i = 0; i < 4; i++) {
        answer = min(answer, dist[start[1].first][start[1].second][i]);
    }

    cout << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];

            if(graph[i][j] == '#') {
                start.push_back({i, j});
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
