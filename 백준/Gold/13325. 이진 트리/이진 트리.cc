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
int K, treesize, answer;
int tree[1 << 22];

int dfs(int Node) {
    if(treesize <= Node) {
        answer += tree[Node];
        return tree[Node];
    }
    else {
        int left = dfs(2 * Node);
        int right = dfs(2 * Node + 1);
        answer += abs(left - right) + tree[Node];
        return tree[Node] + max(left, right);
    }
}

void solve() {
    dfs(1);

    cout << answer;
}

void input() {
    cin >> K;

    treesize = (2 << K) - 1;

    for(int i = 2; i <= treesize; i++) {
        cin >> tree[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
