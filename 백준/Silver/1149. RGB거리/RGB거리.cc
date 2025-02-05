// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    int arr[1001][3];
    int dp[1001][3];

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    dp[1][0] = arr[0][0];
    dp[1][1] = arr[0][1];
    dp[1][2] = arr[0][2];

    for(int i = 2; i <= N; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i-1][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i-1][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i-1][2];
    }

    cout << min({dp[N][0], dp[N][1], dp[N][2]});
}
