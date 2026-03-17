#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 20001;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, k;
vector<int> v;
int dp[10001];

int func(int value) {
    if(value == k) return 0;

    if(value > k) return INF;

    int &ret = dp[value];

    if(ret != -1) return ret;

    ret = INF;

    for(int i = 0; i < n; i++) {
        ret = min(ret, func(value + v[i]) + 1);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    memset(dp, -1, sizeof(dp));

    int answer = func(0);

    if(answer == INF) cout << -1;
    else cout << answer;
}