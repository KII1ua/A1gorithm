// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N, K;
int arr[100001];
int dp[100001];
int res = 0;

void input() {
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void solve() {
    for(int i = 0; i < K; i++) {
        dp[0] += arr[i];
    }

    for(int i = 1; i < N; i++) {
        dp[i] = dp[i-1] - arr[i-1] + arr[(i+K-1)%N];
    }

    for(int i = 0; i < N; i++) {
        res = max(res, dp[i]);
    }

    cout << res;
}

void solution() {
    input();
    solve();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solution();
}
