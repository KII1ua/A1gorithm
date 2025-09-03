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
int N, M, start, en;
const ll INF = 1e11;
vector<vector<pii>> v(10001);

void dijkstra(int a, vector<ll> &dist) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>> pq;
    pq.push({INF, a});
    dist[a] = INF;

    while(!pq.empty()) {
        int Node = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();

        if(dist[Node] > cost) continue;

        for(auto it : v[Node]) {
            int nextNode = it.first;
            int nextCost = (cost > it.second)? it.second : cost;

            if(dist[nextNode] < nextCost) {
                pq.push({nextCost, nextNode});
                dist[nextNode] = nextCost;
            }
        }
    }
}

void solve() {
    vector<ll> dist(N+1);
    dijkstra(start, dist);

    cout << dist[en];
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >>c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    cin >> start >> en;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
