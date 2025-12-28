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
int dp[101][101][101];

int func(int skill, int cnt, int hp) {
    if(hp < 0) return INF;

    if(hp == 0) return 0;

    if(skill >= N) return INF;

    int &ret = dp[skill][cnt][hp];

    if(ret != INF) return ret;

    int ret1 = func(skill+1, 0, hp);

    int cost = v[skill].first + (cnt * K);

    int ret2 = func(skill, cnt+1, hp - v[skill].second) + cost;

    return ret = min(ret1, ret2);
}

void solve() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= M; j++) {
            for(int k = 0; k <= M; k++) {
                dp[i][j][k] = INF;
            }
        }
    }

    cout << func(0, 0, M);
}

void input() {
    cin >> N >> M >> K;

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