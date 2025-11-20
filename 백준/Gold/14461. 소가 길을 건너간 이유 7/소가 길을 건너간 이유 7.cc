#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e15

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
int N, T;
int graph[101][101];
ll dist[101][101][4];

void dijkstra() {
    priority_queue<tuple<ll, int, int, int>, vector<tuple<ll, int, int, int>>, greater<tuple<ll, int, int, int>>> pq;
    dist[0][0][3] = 0;
    pq.push({0, 3, 0, 0});      // 시간, 움직이는 횟수, x, y

    while(!pq.empty()) {
        ll cost = get<0>(pq.top());
        int move = get<1>(pq.top());
        int x = get<2>(pq.top());
        int y = get<3>(pq.top());
        pq.pop();

        if(dist[x][y][move] < cost) continue;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nmove = move-1;
            ll nextCost = cost + T;

            if(nx < 0 || nx >= N || ny < 0|| ny >= N) continue;

            if(nmove == 0) {
                nextCost += graph[nx][ny];

                if(dist[nx][ny][3] > nextCost) {
                    pq.push({nextCost, 3, nx, ny});
                    dist[nx][ny][3] = nextCost;
                }
            }
            else {
                if(dist[nx][ny][nmove] > nextCost) {
                    pq.push({nextCost, nmove, nx, ny});
                    dist[nx][ny][nmove] = nextCost;
                }
            }
        }
    }
}

void Print() {
    for(int k = 0; k < 4; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << dist[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void solve() {
    dijkstra();
    ll answer = MAX;

    for(int i = 0; i < 4; i++) {
        answer = min(answer, dist[N-1][N-1][i]);
    }

    cout << answer << endl;
}

void input() {
    cin >> N >> T;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < 4; k++) {
                dist[i][j][k] = MAX;
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
