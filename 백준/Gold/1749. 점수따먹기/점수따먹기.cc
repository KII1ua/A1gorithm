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
int N, M;
int graph[201][201];
ll dp[201][201];
ll result = -9999999;

void solve() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + graph[i][j] - dp[i-1][j-1];
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            for(int k = i; k <= N; k++) {
                for(int l = j; l <= M; l++) {
                    result = max(result, dp[k][l] - dp[i-1][l] - dp[k][j-1] + dp[i-1][j-1]);
                }
            }
        }
    }

    cout << result;
}

void input() {
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
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