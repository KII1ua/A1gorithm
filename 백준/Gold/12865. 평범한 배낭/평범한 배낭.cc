// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, K;
int dp[101][100001];
int W[101];
int V[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            if(j - W[i] >= 0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[N][K];
}
