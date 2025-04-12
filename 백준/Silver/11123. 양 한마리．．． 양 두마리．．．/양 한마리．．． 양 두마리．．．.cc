#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0};
int dy[] = {0, 0, -1, 1};
int T, N, M;
char graph[101][101];
bool visited[101][101];

void bfs(int x, int y) {
    queue<pii> q;
    visited[x][y] = true;
    q.push(make_pair(x, y));

    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if(nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if(!visited[nx][ny] && graph[nx][ny] == '#') {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

void input() {
    cin >> T;

    while(T--) {
        cin >> N >> M;
        int cnt = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> graph[i][j];
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(graph[i][j] == '#' && !visited[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
        memset(visited, 0, sizeof(visited));
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}