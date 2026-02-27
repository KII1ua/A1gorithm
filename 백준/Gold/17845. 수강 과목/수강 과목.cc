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
int dp[1001][10001];

int func(int idx, int time) {
    if(time > N) return -INF;
    if(idx >= K) return 0;

    int &ret = dp[idx][time];

    if(ret != -1) return ret;

    ret = 0;

    ret = max(func(idx+1, time), func(idx+1, time+v[idx].second) + v[idx].first);

    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cout << func(0, 0);
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