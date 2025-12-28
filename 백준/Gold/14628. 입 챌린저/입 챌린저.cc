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
int N, M, K;
vector<pii> v;
int dp[101];

void solve() {
    for(int i = 0; i < N; i++) {
        int damage = v[i].second;

        for(int j = 1; j <= M; j++) {
            int cost = v[i].first + (j - 1) * K;

            for(int k = M; k >= 0; k--) {
                if(k - damage < 0) continue;
                dp[k] = min(dp[k], dp[k - damage] + cost);
            }
        }
    }

    cout << dp[M];
}

void input() {
    cin >> N >> M >> K;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for(int i = 1; i <= M; i++) {
        dp[i] = INF;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}