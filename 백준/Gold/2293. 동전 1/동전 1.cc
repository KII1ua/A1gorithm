// baekjoon 2206
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, K;
vector<int> v(101);
ll dp[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    dp[0] = 1;

    for(int i = 1; i <= N; i++) {
        for(int j = v[i]; j <= K; j++) {
            dp[j] += dp[j - v[i]];
        }
    }

    cout << dp[K];
}
