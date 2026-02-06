#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 1001;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
int graph[MAX][MAX];
int dist[MAX][MAX];

void dijkstra() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 0, 0});
    dist[0][0] = 0;

    while(!pq.empty()) {
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        int cnt = get<0>(pq.top());
        pq.pop();

        if(x == N-1 && y == M-1) {
            cout << cnt;
            return;
        }

        if(dist[x][y] < cnt) continue;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if(graph[nx][ny] == 1) {
                if(dist[nx][ny] > cnt+1) {
                    pq.push({cnt+1, nx, ny});
                    dist[nx][ny] = cnt+1;
                }
            }
            else {
                if(dist[nx][ny] > cnt) {
                    pq.push({cnt, nx, ny});
                    dist[nx][ny] = cnt;
                }
            }
        }
    }
}

void solve() {
    dijkstra();
}

void input() {
    cin >> M >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            char a;
            cin >> a;
            graph[i][j] = a - '0';
            dist[i][j] = INF;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}