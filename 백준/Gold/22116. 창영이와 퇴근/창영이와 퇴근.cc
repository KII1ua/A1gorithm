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

int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int N;
int graph[1001][1001];
int dist[1001][1001];

void dijkstra() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            dist[i][j] = MAX;
        }
    }
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 0, 0});     // 차이값, 좌표
    dist[0][0] = 0;

    while(!pq.empty()) {
        int gradient = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();

        if(x == N-1 && y == N-1) {
            cout << gradient;
            return;
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= N || nx < 0 || ny >= N || ny < 0) continue;

            if(dist[nx][ny] > gradient) {
                int tmp = abs(graph[nx][ny] - graph[x][y]);
                pq.push({max(tmp, gradient), nx, ny});
                dist[nx][ny] = tmp;
            }
        }
    }
}

void solve() {
    dijkstra();
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}