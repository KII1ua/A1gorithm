#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 2001;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M, K;
char Map1[MAX][MAX];     // 원본
int graph[MAX][MAX];
int dp[MAX][MAX];

int check(int x, int y) {
    int nx = x + K - 1;
    int ny = y + K - 1;

    int ret = dp[nx][ny] - dp[nx-K][ny] - dp[nx][ny-K] + dp[nx-K][ny-K];

    return min(ret, abs((K * K) - ret));
}

void solve() {
    // 체스판 규칙에 의한 고칠곳 초기화
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(i % 2 == 1) {
                if(j % 2 == 1 && Map1[i][j] != 'B') {
                    graph[i][j] = 1;
                }
                else if(j % 2 == 0 && Map1[i][j] != 'W') {
                    graph[i][j] = 1;
                }
            }
            else {
                if(j % 2 == 1 && Map1[i][j] != 'W') {
                    graph[i][j] = 1;
                }
                else if(j % 2 == 0 && Map1[i][j] != 'B') {
                    graph[i][j] = 1;
                }
            }
        }
    }

    // 누적합
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + graph[i][j];
        }
    }

    int answer = INF;
    for(int i = 1; i <= N - K + 1; i++) {
        for(int j = 1; j <= M - K + 1; j++) {
            answer = min(answer, check(i, j));
        }
    }

    cout << answer;
}

void input() {
    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> Map1[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}