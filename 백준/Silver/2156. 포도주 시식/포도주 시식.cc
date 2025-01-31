// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
int dp[10001];
int arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for(int i = 3; i <= N; i++) {
        dp[i] = max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]);
        dp[i] = max(dp[i-1], dp[i]);
    }

    cout << dp[N];
}
