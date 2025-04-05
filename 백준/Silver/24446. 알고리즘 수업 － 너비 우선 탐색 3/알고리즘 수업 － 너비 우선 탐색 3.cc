#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9


int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, M, R;
vector<vector<int>> v(100001);
bool visited[100001];
int dist[100001];

void bfs(int x) {
    queue<int> q;
    visited[x] = true;
    q.push(x);
    dist[x] = 0;

    while(!q.empty()) {
        int xx = q.front();
        q.pop();

        for(auto it : v[xx]) {
            if(!visited[it]) {
                q.push(it);
                visited[it] = true;
                dist[it] = dist[xx] + 1;
            }
        }
    }
}

void solve() {
    bfs(R);

    for(int i = 1; i <= N; i++) {
        if(visited[i]) cout << dist[i] << endl;
        else cout << -1 << endl;
    }
}

void input() {
    cin >> N >> M >> R;

    for(int i = 0; i < M; i++) {
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
