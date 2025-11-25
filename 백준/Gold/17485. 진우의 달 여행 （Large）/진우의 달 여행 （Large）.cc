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
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
int graph[1002][1002];
int dp[1004][1004][3];

void solve() {
    for(int j = 1; j <= M; j++) {
        dp[0][j][0] = dp[0][j][1] = dp[0][j][2] = graph[0][j];
    }

    for(int i = 1; i < N; i++) {
        for(int j = 1; j <= M; j++) {
            dp[i][j][0] = min(dp[i-1][j-1][1], dp[i-1][j-1][2]) + graph[i][j];
            dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][2]) + graph[i][j];
            dp[i][j][2] = min(dp[i-1][j+1][1], dp[i-1][j+1][0]) + graph[i][j];
        }
    }

    int answer = MAX;

    for(int j = 1; j <= M; j++) {
        for(int k = 0; k < 3; k++) {
            answer = min(answer, dp[N-1][j][k]);
        }
    }

    cout << answer;
}

void Init() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= M+2; j++) {
            for(int k = 0; k < 3; k++) {
                dp[i][j][k] = MAX;
            }
        }
    }
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> graph[i][j];
        }
    }

    Init();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
