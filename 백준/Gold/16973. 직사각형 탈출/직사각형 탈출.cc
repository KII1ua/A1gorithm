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
int N, M, H, W, sr, sc, fr, fc;
int graph[MAX][MAX];
bool visited[MAX][MAX];
int dp[MAX][MAX];

bool check(int x, int y) {
    if(x + H - 1> N || y + W -1 > M) return false;

    int startx = x;
    int starty = y;
    int endx = x + H - 1;
    int endy = y + W - 1;

    int value = dp[endx][endy] - dp[endx][starty-1] - dp[startx-1][endy] + dp[startx-1][starty-1];

    if(value != 0) return false;

    return true;
}

void bfs() {
    queue<tuple<int, int, int>> q;
    q.push({sr, sc, 0});
    visited[sr][sc] = 1;

    while(!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        q.pop();

        if(x == fr && y == fc) {
            cout << cnt;
            exit(0);
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <= 0 || nx > N || ny <= 0 || ny >= M) continue;

            if(check(nx, ny) && !visited[nx][ny]) {
                q.push({nx, ny, cnt+1});
                visited[nx][ny] = true;
            }
        }
    }
}

void Print() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + graph[i][j] - dp[i-1][j-1];
        }
    }

    bfs();

    cout << -1;
}

void input() {
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> graph[i][j];
        }
    }

    cin >> H >> W >> sr >> sc >> fr >> fc;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}