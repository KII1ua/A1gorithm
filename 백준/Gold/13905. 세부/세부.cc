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
int N, M, s, e;
vector<vector<pii>> v(100001);
int dist[100001];

void dijkstra(int start) {
    priority_queue<pii, vector<pii>> pq;
    pq.push({MAX, start});
    dist[start] = MAX;

    while(!pq.empty()) {
        int Node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(dist[Node] > cost) continue;

        for(auto it : v[Node]) {
            int nextNode = it.first;
            int nextCost = min(cost, it.second);

            if(dist[nextNode] < nextCost) {
                dist[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }
}

void solve() {
    dijkstra(s);

    cout << dist[e];
}

void input() {
    cin >> N >> M >> s >> e;

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
