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

struct halloween {
    int cnt;
    int score;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};
int dx[] = {1, 0};
int dy[] = {0, 1};
int N, M, start, arrive;
int dist[1001];
vector<vector<pii>> v(1001);

void dijkstra(int start) {
    priority_queue<pii, vector<pii>> pq;
    pq.push({MAX, start});
    dist[start] = MAX;

    while(!pq.empty()) {
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        for(auto it : v[node]) {
            int nextNode = it.first;
            int nextCost = min(cost, it.second);

            if(dist[nextNode] < nextCost) {
                pq.push({nextCost, nextNode});
                dist[nextNode] = nextCost;
            }
        }
    }
}

void solve() {
    dijkstra(start);

    cout << dist[arrive];
}

void input() {
    cin >> N >> M >> start >> arrive;

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
