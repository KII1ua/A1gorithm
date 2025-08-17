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

int dx[] = {0 ,0, -1, 0, 1, 1, -1, -1, 1};
int dy[] = {0, -1, 0, 1, 0, -1, 1, -1, 1};
int N, M;
vector<vector<pii>> v(1001);
int dist[1001];
int dp[1001];

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 2});         // 비용, 노드
    dist[2] = 0;

    while(!pq.empty()) {
        int cost = pq.top().first;
        int Node = pq.top().second;
        pq.pop();

        if(dist[Node] < cost) continue;

        for(auto it : v[Node]) {
            int Nextnode = it.first;
            int totalCost = cost + it.second;

            if(dist[Nextnode] > totalCost) {
                dist[Nextnode] = totalCost;
                pq.push({totalCost, Nextnode});
            }
        }
    }
}

int dfs(int x) {
    if(dp[x] != 0) return dp[x];

    for(auto it : v[x]) {
        int Node = it.first;
        int cost = it.second;

        if(dist[x] > dist[Node]) {
            dp[x] += dfs(Node);
        }
    }

    return dp[x];
}

void solve() {
    dijkstra();

    dp[2] = 1;

    dfs(1);

    cout << dp[1];
}

void Init() {
    for(int i = 1; i <= N; i++) {
        dist[i] = MAX;
    }
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    Init();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
