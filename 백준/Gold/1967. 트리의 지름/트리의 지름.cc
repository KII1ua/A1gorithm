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
bool visited[10001];
int root, len;

void dfs(int node, int lens) {
    if(visited[node]) return;
    visited[node] = true;

    if(len < lens) {
        root = node;
        len = lens;
    }

    for(auto &iter : v[node]) {
        dfs(iter.first, lens + iter.second);
    }
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

    dfs(1, 0);

    memset(visited, 0, sizeof(visited));

    dfs(root, 0);

    cout << len;
}