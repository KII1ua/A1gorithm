#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
};

int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
int N;
vector<vector<int>> v(500001);
bool visited[500001];
vector<int> tmp;
int dp[500001];

void dfscnt(int Node, int depth) {
    visited[Node] = true;
    dp[Node] = depth;

    for(auto it : v[Node]) {
        if(!visited[it]) {
            dfscnt(it, depth+1);
        }
    }
}

void dfs(int Node) {
    visited[Node] = true;
    bool flag = true;

    for(auto it : v[Node]) {
        if(!visited[it]) {
            dfs(it);
            flag = false;
        }
    }

    if(flag) {
        tmp.push_back(Node);
    }
}

void solve() {
    dfs(1);

    memset(visited, 0, sizeof(visited));

    dfscnt(1, 0);

    int result = 0;

    for(auto it : tmp) {
        result += dp[it];
    }

    if(result % 2 == 0) {
        cout << "No";
    }
    else {
        cout << "Yes";
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