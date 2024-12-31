// baekjoon 1753
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
vector<pair<int, int>> vec[300001];
int dist[200001];

bool compare(string a, string b) {
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

void dijkstra(int start) {
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[start], start});      // 현재 비용값, 현재 위치

    while(!pq.empty()) {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i = 0; i < vec[cur].size(); i++) {
            int next = vec[cur][i].first;
            int nextcost = cost + vec[cur][i].second;

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

    int V, E, start;

    cin >> V >> E >> start;

    for(int i = 1; i <= V; i++) {
        dist[i] = int(1e9);
    }

    for(int j = 0; j < E; j++) {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({v, w});
    }

    dijkstra(start);

    for(int k = 1; k <= V; k++) {
        if(dist[k] == int(1e9)) cout << "INF" << endl;
        else cout << dist[k] << endl;
    }
}