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
int dp[100001];
vector<pii> v;

void solve() {
    for(int i = 0; i < N; i++) {
        int weight = v[i].first;
        int cost = v[i].second;

        for(int j = K; j >= 0; j--) {
            if(j - weight < 0) continue;
            dp[j] = max(dp[j], dp[j - weight] + cost);
        }
    }

    cout << dp[K];
}

void input() {
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}