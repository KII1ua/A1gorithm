#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 100001;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
vector<vector<pii>> v(10001);
int dp[10001];
bool visited[10001];
int answer;

pii dfs(int node, int par) {
    pii max_value = {node, 0};

    for(auto &iter : v[node]) {
        int nextnode = iter.first;
        int nextcost = iter.second;

        if(nextnode == par) continue;
        pii tmp = dfs(nextnode, node);
        tmp.second += nextcost;

        if(max_value.second < tmp.second) {
            max_value = tmp;
        }
    }

    return max_value;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 0; i < N-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    dfs(1, -1);

    cout << dfs(dfs(1, -1).first, -1).second;
}