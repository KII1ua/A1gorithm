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
int N;
int graph[51][51];
int dist[51][51];

void dijkstra() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 0, 0});     // 벽 부순 값, x, y

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            dist[i][j] = MAX;
        }
    }

    while(!pq.empty()) {
        int cnt = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
                int cost = cnt + graph[nx][ny];

                if(dist[nx][ny] > cost) {
                    dist[nx][ny] = cost;
                    pq.push({cost, nx, ny});
                }
            }
        }
    }
}

void solve() {
    dijkstra();

    cout << dist[N-1][N-1];
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            char a;
            cin >> a;
            if(a == '0') {
                graph[i][j] = 1;
            }
            else graph[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}