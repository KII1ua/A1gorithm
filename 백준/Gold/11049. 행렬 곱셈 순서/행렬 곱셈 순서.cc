#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 501;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int dp[MAX][MAX];
vector<pii> v;

int func(int start, int end) {
    if(start == end) return 0;
    int &ret = dp[start][end];

    if(ret != -1) return ret;

    ret = INF;

    for(int i = start; i < end; i++) {
        ret = min(ret, func(start, i) + func(i+1, end) + v[start].first * v[i].second * v[end].second);
    }

    return ret;
}

void solve() {
    cout << func(0, N-1);
}

void input() {
    cin >> N;

    memset(dp, -1, sizeof(dp));

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