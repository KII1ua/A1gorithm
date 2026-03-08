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
int T, W;
int dp[1001][3][31];

int func(int idx, int locate, int count, vector<int> &v) {
    if(idx >= T) return 0;

    int &ret = dp[idx][locate][count];

    if(ret != -1) return ret;

    ret = 0;

    if(v[idx] == locate) {
        ret = max(ret, func(idx+1, locate, count, v) + 1);
    }
    else {
        if(count + 1 <= W) {
            ret = max(ret, func(idx+1, v[idx], count+1, v) + 1);
        }
        ret = max(ret, func(idx+1, locate, count, v));
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T >> W;

    vector<int> v(T, 0);

    for(auto &iter: v) {
        cin >> iter;
    }

    memset(dp, -1, sizeof(dp));

    cout << func(0, 1, 0, v);
}