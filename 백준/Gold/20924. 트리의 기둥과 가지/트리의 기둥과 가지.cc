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

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, R, gigaNode, pillar, answer, par;
int dist[200001];
vector<vector<pii>> v(200001);
bool flag;

void findGiga(int Node, int parent, int dist) {
    if(flag) return;
    int leaf = 0;

    int nextNode = 0;
    int cost = 0;
    for(auto it : v[Node]) {
        int Next = it.first;
        int cst = it.second;

        if(parent == Next) continue;

        leaf++;
        nextNode = Next;
        cost = cst;
    }

    if(leaf != 1) {
        par = parent;
        gigaNode = Node;
        pillar = dist;
        flag = true;
        return;
    }

    findGiga(nextNode, Node, dist+cost);
}

void dfs(int Node, int parent, int dst) {

    for(auto it : v[Node]) {
        int nextNode = it.first;
        int cost = it.second;

        if(parent == nextNode) continue;
        dfs(nextNode, Node, dst + cost);
    }
    answer = max(answer, dst);
}

void solve() {
    findGiga(R, -1, 0);

    for(auto it : v[gigaNode]) {
        int next = it.first;
        int cost = it.second;

        if(next == par) continue;

        dfs(next, gigaNode, cost);
    }

    cout << pillar << " " << answer;
}

void input() {
    cin >> N >> R;

    for(int i = 0; i < N-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
