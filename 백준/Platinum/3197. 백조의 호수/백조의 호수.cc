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

int dx[] = {0, 1, -1, 0,1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int R, C;
char graph[1501][1501];
int dist[1501][1501];
bool visited[1501][1501];
queue<tuple<int, int, int>> distq;
queue<tuple<int, int, int>> q;
vector<pii> arr;

void Init() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            dist[i][j] = MAX;
        }
    }
}

void Print() {
    for(int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void distbfs() {
    while(!distq.empty()) {
        int x = get<1>(distq.front());
        int y = get<2>(distq.front());
        int cost = get<0>(distq.front());
        distq.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= R || nx < 0 || ny >= C || ny < 0) continue;

            if(dist[nx][ny] <= cost + 1) continue;

            if(graph[nx][ny] == 'X') {
                distq.push({cost+1, nx, ny});
                dist[nx][ny] = cost+1;
            }
        }
    }
}

void bfs(int day) {
    queue<tuple<int, int, int>> tmpq;

    while(!q.empty()) {
        int x = get<1>(q.front());
        int y = get<2>(q.front());
        int cost = get<0>(q.front());
        q.pop();

        if(x == arr[1].first && y == arr[1].second) {
            cout << day;
            exit(0);
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= R || nx < 0 || ny >= C || ny < 0 || visited[nx][ny]) continue;

            if(dist[nx][ny] == day + 1) {
                tmpq.push({day+1, nx, ny});
                visited[nx][ny] = true;
            }

            if(dist[nx][ny] <= day) {
                q.push({day, nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    swap(q, tmpq);
}

void solve() {
    distbfs();
    q.push({0,arr[0].first, arr[0].second});
    visited[arr[0].first][arr[0].second] = true;

    int cnt = 0;
    while(true) {
        bfs(cnt);
        cnt++;
    }
}

void input() {
    cin >> R >> C;

    Init();

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> graph[i][j];

            if(graph[i][j] == '.') {
                distq.push({0, i, j});
                dist[i][j] = 0;
            }

            if(graph[i][j] == 'L') {
                arr.push_back({i, j});
                distq.push({0, i, j});
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