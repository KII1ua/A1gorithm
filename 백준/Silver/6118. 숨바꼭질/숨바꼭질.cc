// baekjoon 2206
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, M;
vector<vector<int>> v(20001);
bool visited[20001];
int dist[20001];

void bfs(int x, int cnt) {
    queue<pii> q;

    q.push(make_pair(x, 0));
    visited[x] = true;

    while(!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for(int i = 0; i < v[cur].size(); i++) {
            if(!visited[v[cur][i]]) {
                q.push(make_pair(v[cur][i], cnt+1));
                visited[v[cur][i]] = true;
                dist[v[cur][i]] = cnt+1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int result = 0;
    int cnt = 0;

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs(1, 0);

    for(int i = 1; i <= N; i++) {
        if(dist[i] > result) {
            result = dist[i];
        }
    }

    for(int i = 1; i <=N; i++) {
        if(dist[i] == result) cnt++;
    }

    for(int i = 1; i <= N; i++) {
        if(dist[i] == result) {
            cout << i << " ";
            break;
        }
    }

    cout << result << " " << cnt;
}
