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

int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};
int T;
int parent[1026];
int depth[1026];

void dfs(int Node, int par, int dep) {
    if(Node >= 1024) return;
    parent[Node] = par;
    depth[Node] = dep;

    dfs(Node * 2, Node, dep+1);
    dfs(Node * 2 + 1, Node, dep+1);
}

void solve() {
    dfs(1, 0, 0);

    for(int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;

        int deepa = depth[a];
        int deepb = depth[b];

        while(deepa > deepb) {
            a = parent[a];
            deepa--;
        }

        while(deepa < deepb) {
            b = parent[b];
            deepb--;
        }

        while(a != b) {
            a = parent[a];
            b = parent[b];
        }

        cout << a * 10<< endl;
    }
}

void input() {
    cin >> T;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
