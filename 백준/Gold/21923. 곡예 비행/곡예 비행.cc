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
int dp[1002][1002];
int graph[1002][1002];

void solve() {
    dp[N-1][0] = graph[N-1][0];

    for(int i = N-1; i >= 0; i--) {
        for(int j = 0; j < M; j++) {
            if(j != 0) dp[i][j] = max(dp[i][j], dp[i][j-1] + graph[i][j]);      // 왼쪽에서 오는 경우
            if(i != N-1) dp[i][j] = max(dp[i][j], dp[i+1][j] + graph[i][j]);    // 아래에서 오는 경우
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            dp[i][j] += graph[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(j != 0) dp[i][j] = max(dp[i][j], dp[i][j-1] + graph[i][j]);
            if(i != 0) dp[i][j] = max(dp[i][j], dp[i-1][j] + graph[i][j]);
        }
    }

    cout << dp[N-1][M-1];
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++)  {
            cin >> graph[i][j];
            dp[i][j] = -MAX;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
