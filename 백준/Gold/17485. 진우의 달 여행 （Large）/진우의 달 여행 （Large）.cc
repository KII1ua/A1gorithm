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

// int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
// int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};
int dx[] = {1, 1, 1};
int dy[] = {-1, 0, 1};
int N, M;
int graph[1001][1001];
int dp[1001][1001][4];

void Init() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            for(int k = 0; k < 3; k++) {
                dp[i][j][k] = MAX;
            }
        }
    }
}

void solve() {
    Init();

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 3; j++) {
            dp[0][i][j] = graph[0][i];
        }
    }

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < M; j++) {
            for(int k = 0; k < 3; k++) {
                int prevx = i-1;
                int prevy = j - dy[k];

                if(prevy < 0 || prevy >= M) continue;

                int cost = MAX;

                for(int d = 0; d < 3; d++) {
                    if(k == d) continue;
                    cost = min(cost, dp[prevx][prevy][d]);
                }
                if(cost != MAX) dp[i][j][k] = cost + graph[i][j];
            }
        }
    }

    int answer = MAX;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 3; j++) {
            answer = min(answer, dp[N-1][i][j]);
        }
    }

    cout << answer;
}

void input() {
    cin >> N >> M;

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
