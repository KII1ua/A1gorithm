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

struct halloween {
    int cnt;
    int score;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, S, D, answer;
int depth[100001];
vector<vector<int>> v(100001);

int dfs(int Node, int par) {
    for(auto it : v[Node]) {
        if(it != par) {
            depth[Node] = max(depth[Node], dfs(it, Node) + 1);
        }
    }

    if(depth[Node] >= D && Node != S) {
        answer++;
    }
    return depth[Node];
}

void solve() {
    dfs(S, -1);

    cout << answer * 2;
}

void input() {
    cin >> N >> S >> D;

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
