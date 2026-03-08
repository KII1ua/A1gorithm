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

ll func(int idx, vector<ll> &dp, vector<pii> &v) {
    if(idx > N) return -INF;
    ll &ret = dp[idx];

    if(ret != -1) return ret;

    ret = 0;

    ret = max(ret, func(idx+1, dp, v));        // 선택하지 않은 경우

    if(v[idx].first + idx <= N) {
        ret = max(ret, func(idx + v[idx].first, dp, v) + v[idx].second);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    vector<pii> v(N, {0, 0});
    vector<ll> dp(N+1, -1);

    for(auto &iter : v) {
        cin >> iter.first >> iter.second;
    }

    cout << func(0, dp, v);
}