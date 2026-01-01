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
pii walk[102];
pii cycle[102];
int dp[102][100001];

int func(int Node, int time) {
    if(time > K) return -INF;

    if(Node == N) return 0;

    int &ret = dp[Node][time];

    if(ret != -1) return ret;

    ret = 0;

    ret = max(func(Node + 1, time + walk[Node + 1].first) + walk[Node+1].second, func(Node + 1, time + cycle[Node + 1].first) + cycle[Node+1].second);

    return ret;
}

void solve() {
    cout << func(0, 0);
}

void input() {
    cin >> N >> K;

    memset(dp, -1, sizeof(dp));

    for(int i = 1; i <= N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        walk[i].first = a;
        walk[i].second = b;
        cycle[i].first = c;
        cycle[i].second = d;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}