#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M, T, D, answer;
int graph[26][26];
int dist[26][26];
int downdist[26][26];

void Print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << downdist[i][j] << " ";
        }
        cout << endl;
    }
}

void dijkstra() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 0, 0});
    dist[0][0] = 0;
    
    answer = graph[0][0];

    while(!pq.empty()) {
        int time = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();

        if(dist[x][y] < time) continue;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            int h1 = graph[x][y];
            int h2 = graph[nx][ny];
            
            if(abs(h1 - h2) > T) continue;

            int ntime;

            if(h2 > h1) {
                ntime = (h2 - h1) * (h2 - h1);
            }
            else ntime = 1;

            if(dist[nx][ny] > ntime + time) {
                dist[nx][ny] = ntime + time;
                pq.push({dist[nx][ny], nx, ny});
            }
        }
    }
}

void downdijkstra() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 0, 0});
    downdist[0][0] = 0;

    while(!pq.empty()) {
        int time = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();

        if(downdist[x][y] < time) continue;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            int h_curr = graph[x][y];
            int h_next = graph[nx][ny];
            
            if(abs(h_curr - h_next) > T) continue;

            int ntime;

            if (h_curr > h_next) {
                ntime = (h_curr - h_next) * (h_curr - h_next);
            }
            else {
                ntime = 1;
            }

            if(downdist[nx][ny] > ntime + time) {
                downdist[nx][ny] = ntime + time;
                pq.push({downdist[nx][ny], nx, ny});
            }
        }
    }
}

void solve() {
    dijkstra();
    downdijkstra();

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(dist[i][j] == MAX || downdist[i][j] == MAX) continue;
            
            if(dist[i][j] + downdist[i][j] <= D) {
                answer = max(answer, graph[i][j]);
            }
        }
    }

    cout << answer << endl;
}

void Init() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            dist[i][j] = MAX;
            downdist[i][j] = MAX;
        }
    }
}

void input() {
    cin >> N >> M >> T >> D;

    Init();

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            char c;
            cin >> c;

            if(c >= 'A' && c <= 'Z') {
                graph[i][j] = c - 'A';
            }
            else {
                graph[i][j] = c - 'a' + 26;
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