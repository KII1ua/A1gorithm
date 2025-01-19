// baekjoon 1504
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, M, X;
vector<vector<pair<int, int>>> v(1001);
vector<int> tmp;
int dist[1001];
int res[1001];

void dijkstra(int x) {
    for(int i = 1; i <= N; i++) {
        dist[i] = INF;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[x] = 0;
    pq.push({x, dist[x]});      // 현재 위치, 비용

    while(!pq.empty()) {
        int cur = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i = 0; i < v[cur].size(); i++) {
            int nextcur = v[cur][i].first;
            int nextcost = cost + v[cur][i].second;

            if(dist[nextcur] > nextcost) {
                dist[nextcur] = nextcost;
                pq.push({nextcur, dist[nextcur]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int a, b, c;
    int result = 0;

    cin >> N >> M >> X;

    for(int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    for(int j = 1; j <= N; j++) {
        if(j == X) continue;
        dijkstra(j);
        res[j] = dist[X];
    }

    dijkstra(X);

    for(int k = 1; k <= N; k++) {
        result = max(res[k] + dist[k], result);
    }

    cout << result;
}
