#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 200000;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    vector<pii> v(N, {0, 0});
    vector<ll> dp(N+1, 0);

    for(auto &iter : v) {
        cin >> iter.first >> iter.second;
    }

    if(v[0].first <= N)  {
        dp[v[0].first] = max(dp[0] + v[0].second, dp[v[0].first]);
    }

    for(int i = 1; i < N; i++) {
        // 안하는 경우
        if(i+1 <= N) dp[i+1] = max(dp[i], dp[i+1]);

        // 하는경우
        if(i + v[i].first <= N) {
            dp[i+v[i].first] = max(dp[i] + v[i].second, dp[i+v[i].first]);
        }
    }

    cout << dp[N];
}