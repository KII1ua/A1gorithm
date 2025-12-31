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
int N, M;
int depth[5001];
vector<vector<int>> v(5001);
int dp[5001];
pii min_depth = {0, INF};

int func(int Node) {
    int &ret = dp[Node];

    if(ret != -1) return ret;

    ret = 1;

    for(auto it : v[Node]) {
        ret = max(ret, func(it) + 1);
    }

    return ret;
}

void solve() {
    func(min_depth.first);

    for(int i = 1; i <= N; i++) {
        cout << func(i) << endl;
    }
}

void input() {
    cin >> N >> M;

    memset(dp, -1, sizeof(dp));

    for(int i = 1; i <= N; i++) {
        cin >> depth[i];

        if(min_depth.second > depth[i]) {
            min_depth.first = i;
            min_depth.second = depth[i];
        }
    }

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        if(depth[a] < depth[b]) {
            v[a].push_back(b);
        }
        else if(depth[a] > depth[b]) {
            v[b].push_back(a);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}