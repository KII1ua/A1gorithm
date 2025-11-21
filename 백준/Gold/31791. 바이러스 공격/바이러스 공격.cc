#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9;

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
int N, M, tg, tb, X, B;     // 격자, 바이러스 전파 시간, 건물 전파 시간, 바이러스 개수, 건물 개수
char graph[1001][1001];         // . -> 빈칸, * -> 바이러스, # -> 건물
ll dist[1001][1001];
priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;

void dijkstra() {
    while(!pq.empty()) {
        ll cost = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            ll nextCost = cost + 1;

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if(graph[nx][ny] == '#') {
                nextCost += tb;
            }

            if(dist[nx][ny] > nextCost) {
                dist[nx][ny] = nextCost;
                pq.push({nextCost, nx, ny});
            }
        }
    }
}

void Print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    dijkstra();

    int answer = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(dist[i][j] > tg) {
                cout << i+1 << " " << j+1 << endl;
                answer++;
            }
        }
    }

    if(answer == 0) {
        cout << -1;
    }
}

void input() {
    cin >> N >> M >> tg >> tb >> X >> B;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];

            dist[i][j] = MAX;

            if(graph[i][j] == '*') {
                pq.push({0, i, j});
                dist[i][j] = 0;
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
