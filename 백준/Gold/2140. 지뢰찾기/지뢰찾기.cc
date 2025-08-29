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

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, cnt;
char graph[101][101];
int dp[101][101];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>>pq;
bool visited[101][101];
vector<pii> v;

/*
    bfs로 숫자로 탐색하여
*/

void Print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs(int a, int b) {
    queue<pii> q;
    vector<pii> tmp;
    q.push({a, b});
    int cnt = dp[a][b];

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if(graph[nx][ny] != '#') continue;

            if(cnt - 1 < 0) {
                graph[nx][ny] = '.';
            }
            else {
                graph[nx][ny] = '*';
                tmp.push_back({nx, ny});
            }
        }
    }

    for(auto it : tmp) {        // 만들었던 지뢰에서 상, 하, 좌, 우, 대각선 1씩 줄이기
        int x = it.first;
        int y = it.second;

        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if(dp[nx][ny] > 0) {        // 지뢰 개수 줄여줘야함
                dp[nx][ny]--;
            }
        }
    }
}

void solve() {
    for(auto it : v) {
        int col = it.first;
        int row = it.second;

        bfs(col, row);
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(graph[i][j] >= 48 && graph[i][j] <= 57) {
                bfs(i, j);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(graph[i][j] == '*' || graph[i][j] == '#') {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}


void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];

            if((i == 0 || i == N-1) && (j == 0 || j == N-1)) {
                v.push_back({i, j});
            }

            if(graph[i][j] != '#') {
                dp[i][j] = graph[i][j] - '0';
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
