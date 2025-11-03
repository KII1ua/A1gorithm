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

struct halloween {
    int cnt;
    int score;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};
int dx[] = {0, -1, 1, 0};
int dy[] = {1, 0, 0, 1};
int N, M;
int graph[1001][1001];
int dp[1001][1001][2];

int func(int x, int y, int status) {
    int &ret = dp[x][y][status];
    if(ret != -1) return ret;

    int score = graph[x][y];

    if(x == N-1 && y == M-1 && !status) return score;
    ret = -MAX;

    if(status) {        // 올라가기
        if(x - 1 >= 0) {
            ret = max(ret, func(x-1, y, 1) + score);
        }

        if(y + 1 <= M - 1) {
            ret = max(ret, func(x, y+1, 1) + score);
        }

        ret = max(ret, func(x, y, 0) + score);
    }
    else {
        if(x + 1 <= N - 1) {
            ret = max(ret, func(x + 1, y, 0) + score);
        }

        if(y + 1 <= M - 1) {
            ret = max(ret, func(x, y+1, 0) + score);
        }
    }

    return ret;
}

void Print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    cout << func(N-1, 0, 1) << endl;
}

void input() {
    cin >> N >> M;

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
