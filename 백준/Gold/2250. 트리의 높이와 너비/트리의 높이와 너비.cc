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
int N, row;
pii answer[10001];
int par[10001];
Tree graph[10001];
int cnt[10001];

void dfs(int Node, int dep) {

    if(graph[Node].left != -1) {
        dfs(graph[Node].left, dep+1);
    }

    cnt[Node] = ++row;
    answer[dep].first = min(answer[dep].first, cnt[Node]);
    answer[dep].second = max(answer[dep].second, cnt[Node]);

    if(graph[Node].right != -1) {
        dfs(graph[Node].right, dep+1);
    }
}

void solve() {
    int root = 0;

    for(int i = 1; i <= N; i++) {
        if(!par[i]) {
            root = i;
        }
    }

    dfs(root, 1);

    pii ans = {0, 0};

    for(int i = 1; i <= N; i++) {
        if(answer[i].first == INF) break;

        int left = answer[i].first;
        int right = answer[i].second;

        int tmp = right - left + 1;

        if(tmp > ans.second) {
            ans.first = i;
            ans.second = tmp;
        }
    }

    cout << ans.first << " " << ans.second << endl;
}

void input() {
    cin >> N;

    for(int i = 1; i <= N; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        graph[a].left = b;
        graph[a].right = c;

        answer[i].first = INF;

        if(b != -1) {
            par[b] = a;
        }

        if(c != -1) {
            par[c] = a;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}