// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
vector<vector<int>> v(101);
bool visited[101];
int n, x, y, m, a, b, result;

void dfs(int start, int cnt) {
    visited[start] = true;

    for(int i = 0; i < v[start].size(); i++) {
        if(!visited[v[start][i]]) {
            visited[v[start][i]] = true;
            dfs(v[start][i], cnt+1);
        }

        if(start == b) {
            result = cnt;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> a >> b >> m;

    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(a, 0);

    if(result == 0) {
        cout << -1;
        return 0;
    }
    cout << result;
}
