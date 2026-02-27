#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 4000000;
const int D = 2000000;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, K;
vector<pii> v;
int dp[10001];

void solve() {
    for(int i = 0; i < K; i++) {
        int value = v[i].first;
        int time = v[i].second;

        for(int j = N; j >= time; j--) {
            dp[j] = max(dp[j - time] + value, dp[j]);
        }
    }

    cout << dp[N];
}

void input() {
    cin >> N >> K;

    for(int i = 0; i < K; i++) {
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