#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

int dx[] = {0, 1, -1, 0,1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int N, R, Q;
vector<vector<int>> v(100001);
bool visited[100001];
int dp[100001];

int dfs(int x) {
    visited[x] = true;

    dp[x] = 1;

    for(auto it : v[x]) {
        if(!visited[it]) {
            dp[x] += dfs(it);
        }
    }

    return dp[x];
}

void solve() {
    dfs(R);
}

void input() {
    cin >> N >> R >> Q;

    for(int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    solve();

    for(int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        cout << dp[a] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}