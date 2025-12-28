#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, K;
int arr[101];
int dp[100001];

void solve() {
    for(int i = 0; i < N; i++) {
        int caffee = arr[i];

        for(int j = K; j >= 0; j--) {
            if(j - caffee < 0) continue;
            dp[j] = min(dp[j], dp[j - caffee] + 1);
        }
    }

    if(dp[K] == INF) {
        cout << -1;
    }
    else cout << dp[K];
}

void input() {
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i <= K; i++) {
        dp[i] = INF;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}