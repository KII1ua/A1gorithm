#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 123457;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
vector<vector<pii>> v(1001);
int dist[1001];
int dp[1001];

int func(int node) {
    int &ret = dp[node];

    if(ret != -1) return ret;

    ret = 0;

    for(auto &it : v[node]) {
        int nextNode = it.first;
        int cost = it.second;
        int score = 0;

        if(nextNode == 1) {
            score = cost;
        }
        else {
            score = cost + func(nextNode);
        }

        if(score > ret) {
            ret = score;
            dist[node] = nextNode;
        }
    }

    return ret;
}

void solve() {
    cout << func(1) << endl;

    vector<int> ans;
    ans.push_back(1);

    int idx = 1;

    do {
        idx = dist[idx];
        ans.push_back(idx);
    } while(idx != 1);

    for(auto it : ans) {
        cout << it << " ";
    }
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    memset(dp, -1, sizeof(dp));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}