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

int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int N, color, start;
int graph[20][20];
bool visited[20][20];

bool is_check(int x, int y) {
    return x >= 1 && x <= 19 && y >= 1 && y <= 19;
}

bool bfs(int x, int y, int z) {
    queue<pii> q;
    visited[x][y] = true;
    q.push({x, y});
    int cnt = 1;

    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for(int i = z; i < z + 2; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if(is_check(nx, ny) && graph[nx][ny] == color && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }

    if(cnt == 5) return true;
    else return false;
}

void solve(int x, int y) {
    for(int i = 0; i < 8; i += 2) {
        memset(visited, 0, sizeof(visited));
        if(bfs(x, y, i)) {
            cout << start + 1;
            exit(0);
        }
    }
}

void input() {
    cin >> N;

    for(start = 0; start < N; start++) {
        int a, b;
        cin >> a >> b;

        if(start % 2 == 0) {
            graph[a][b] = 2;
        }
        else graph[a][b] = 1;

        color = graph[a][b];

        solve(a, b);
    }

    cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}