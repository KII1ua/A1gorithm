// baekjoon 1916
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
vector<pair<int, int>> vec[100001];
int dist[1001];

bool compare(string a, string b) {
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({dist[start], start});

    while(!pq.empty()) {
        int cur = pq.top().second;          // 현재 위치
        int cost = pq.top().first * -1;     // 현재 비용 * -1 를 해야 실제 비용 값이 나옴
        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i = 0; i < vec[cur].size(); i++) {
            int next = vec[cur][i].first;           // 간선에 대한 위치
            int nextcost = cost + vec[cur][i].second;      // 현재 위치 + 간선 비용 -> 가려고 하는 총(누적) 비용

            if(dist[next] > nextcost) {
                dist[next] = nextcost;
                pq.push({nextcost * -1, next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M, start, end;

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        dist[i] = int(1e9);
    }

    for(int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({v, w});
    }

    cin >> start >> end;

    dijkstra(start);

    cout << dist[end];
}