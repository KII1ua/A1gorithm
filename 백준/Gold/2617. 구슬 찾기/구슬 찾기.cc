// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N, M;
vector<vector<int>> v1(100);
vector<vector<int>> v2(100);
bool visited[100];
int sol = 0;

int bfs(int x, vector<vector<int>> v) {
    queue<int> q;

    int result = 0;

    for(int i = 0; i < 100; i++) {
        visited[i] = false;
    }

    visited[x] = true;
    q.push(x);

    while(!q.empty()) {
        int dx = q.front();
        q.pop();

        for(int i = 0; i < v[dx].size(); i++) {
            if(visited[v[dx][i]]) continue;
            visited[v[dx][i]] = true;
            q.push(v[dx][i]);
            result++;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        v1[a].push_back(b);
        v2[b].push_back(a);
    }

    for(int i = 1; i <= N; i++) {
        int cnt = bfs(i, v1);
        int res = bfs(i, v2);

        if(cnt > ((N-1) / 2) || res > ((N-1) / 2)) sol++;
    }

    cout << sol;
}
