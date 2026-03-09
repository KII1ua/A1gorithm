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
int N, W;
vector<pii> v;
int dp[1002][1002];

int func(int a, int b) {
    int next = max(a, b) + 1;

    if(next > W) return 0;

    int &ret = dp[a][b];

    if(ret != -1) return ret;

    int cost1;
    int cost2;

    ret = 0;

    if(a == 0) {
        cost1 = abs(1 - v[next].first) + abs(1 - v[next].second);
    }
    else cost1 = abs(v[a].first - v[next].first) + abs(v[a].second - v[next].second);

    if(b == 0) {
        cost2 = abs(N - v[next].first) + abs(N - v[next].second);
    }
    else cost2 = abs(v[b].first - v[next].first) + abs(v[b].second - v[next].second);

    ret = min(func(next, b) + cost1, func(a, next) + cost2);

    return ret;
}

void trace(int a, int b) {
    int next = max(a, b) + 1;

    if(next > W) return;

    int cost1;
    int cost2;

    if(a == 0) {
        cost1 = abs(1 - v[next].first) + abs(1 - v[next].second);
    }
    else cost1 = abs(v[a].first - v[next].first) + abs(v[a].second - v[next].second);

    if(b == 0) {
        cost2 = abs(N - v[next].first) + abs(N - v[next].second);
    }
    else cost2 = abs(v[b].first - v[next].first) + abs(v[b].second - v[next].second);

    if(dp[next][b] + cost1 > dp[a][next] + cost2)  {
        cout << 2 << endl;
        trace(a, next);
    }
    else {
        cout << 1 << endl;
        trace(next, b);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> W;

    v.push_back({0, 0});

    for(int i = 0; i < W; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    memset(dp, -1, sizeof(dp));

    cout << func(0, 0) << endl;

    trace(0, 0);
}