#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N;
vector<pii> v[10001];
bool visited[10001];
int result;
int endpoint;

void dfs(int a, int len) {
    if(visited[a]) return;

    visited[a] = true;
    if(result < len) {
        result = len;
        endpoint = a;
    }

    for(int i = 0; i < v[a].size(); i++) {
        dfs(v[a][i].first, len + v[a][i].second);
    }
}

void input() {
    cin >> N;

    for(int i = 0; i < N-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
}

void solve() {
    input();
    dfs(1, 0);

    memset(visited, 0, sizeof(visited));

    dfs(endpoint, 0);

    cout << result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();
}
