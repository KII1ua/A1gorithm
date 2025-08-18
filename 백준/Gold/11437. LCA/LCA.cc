#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
    int r;
};

int dx[] = {0 ,0, -1, 0, 1, 1, -1, -1, 1};
int dy[] = {0, -1, 0, 1, 0, -1, 1, -1, 1};
int N, M;
vector<vector<int>> v(50001);
int parent[50001], lv[50001];

void dfs(int Node, int depth, int par) {
    lv[Node] = depth;
    parent[Node] = par;

    for(auto it : v[Node]) {
        if(it == par) continue;
        dfs(it, depth+1, Node);
    }
}

void solve() {
    dfs(1, 0, 0);

    cin >> M;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        int l_depth = lv[a], r_depth = lv[b];

        while(l_depth > r_depth) {
            a = parent[a];
            l_depth--;
        }

        while(l_depth < r_depth) {
            b = parent[b];
            r_depth--;
        }

        while(a != b) {
            a = parent[a];
            b = parent[b];
        }

        cout << a << endl;
    }
}

void input() {
    cin >> N;

    for(int i = 0; i < N-1; i++) {
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
