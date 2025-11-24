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
char graph[301][301];
int dist[301][301];

void dijkstra() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, startx, starty});
    dist[startx][starty] = 0;

    while(!pq.empty()) {
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        int time = get<0>(pq.top());
        pq.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if(graph[nx][ny] != '0') {
                if(dist[nx][ny] > time+1) {
                    pq.push({time+1, nx, ny});
                    dist[nx][ny] = time+1;
                }
            }
            else {
                if(dist[nx][ny] > time) {
                    pq.push({time, nx, ny});
                    dist[nx][ny] = time;
                }
            }
        }
    }
}

void solve() {
    dijkstra();

    cout << dist[endx][endy];
}


void input() {
    cin >> N >> M >> startx >> starty >> endx >> endy;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];
            dist[i][j] = MAX;
        }
    }
    startx--,starty--,endx--,endy--;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
