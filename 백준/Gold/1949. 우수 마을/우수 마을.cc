#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int arr[10001];
int dp[10001][2];
vector<vector<int>> v(10001);

int dfs(int Node, int par, int status) {
    if(dp[Node][status] != -1) return dp[Node][status];

    int &ret = dp[Node][status];
    ret = 0;

    if(status == 0) {
        for(auto iter : v[Node]) {
            if(par != iter) {
                ret += max(dfs(iter, Node, 0), dfs(iter, Node, 1));
            }
        }
    }
    else {
        ret += arr[Node];
        for(auto iter : v[Node]) {
            if(par != iter) {
                ret += dfs(iter, Node, 0);
            }
        }
    }

    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));

    dfs(1, -1, 0);
    dfs(1, -1, 1);

    cout << max(dp[1][0], dp[1][1]);
}

void input() {
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}