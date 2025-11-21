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
int N, M, startx, starty, endx, endy, answer;
char graph[501][501];
int dist[501][501];
bool visited[501][501];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

void dijkstra() {
    while(!pq.empty()) {
        int cost = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nextCost = cost + 1;

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if(dist[nx][ny] > nextCost) {
                dist[nx][ny] = nextCost;
                pq.push({nextCost, nx, ny});
            }
        }
    }
}

void Print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void dijkstras() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>> pq1;
    pq1.push({dist[startx][starty], startx, starty});
    visited[startx][starty] = true;

    while(!pq1.empty()) {
        int cost = get<0>(pq1.top());
        int x = get<1>(pq1.top());
        int y = get<2>(pq1.top());
        pq1.pop();

        if(x == endx && y == endy) {
            cout << cost;
            return;
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if(!visited[nx][ny]) {
                pq1.push({min(cost, dist[nx][ny]), nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

void solve() {
    dijkstra();

    dijkstras();
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];

            dist[i][j] = MAX;

            if(graph[i][j] == '+') {
                pq.push({0, i, j});
                dist[i][j] = 0;
            }

            if(graph[i][j] == 'V') startx = i, starty = j;

            if(graph[i][j] == 'J') endx = i, endy = j;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
