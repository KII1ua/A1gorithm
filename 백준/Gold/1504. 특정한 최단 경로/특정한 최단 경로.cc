// baekjoon 1504
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
vector<pair<int, int>> v[200001];
int dist[801];
int N, E;

void dijkstra(int x) {
    for(int i = 1; i <= N; i++) {
        dist[i] = INF;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[x] = 0;

    pq.push({dist[x], x});       // 비용값, 현재 위치

    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;     // 연결된 간선의 정점
            int nextcost = cost + v[cur][i].second;    // 간선 비용

            if(dist[next] > nextcost) {
                dist[next] = nextcost;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int a, b, c, v1, v2;

    cin >> N >> E;

    for(int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    cin >> v1 >> v2;

    dijkstra(v1);

    ll a1 = dist[1];
    ll a2 = dist[v2];
    ll a3 = dist[N];

    dijkstra(v2);

    ll b1 = dist[1];
    ll b2 = dist[N];

    ll ans1 = a1 + a2 + b2;
    ll ans2 = b1 + a2 + a3;
    ll ans = min(ans1, ans2);

    if(ans >= int(1e9)) ans = -1;

    cout << ans;
}
