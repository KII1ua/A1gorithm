// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, M;
int dist[201];
vector<vector<pii>> v(201);
vector<int> tmp;

void dijkstra(int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for(int i = 1; i <= N; i++) {
        dist[i] = INF;
    }

    dist[start] = 0;

    pq.push(make_pair(start, dist[start]));

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
                pq.push(make_pair(nextcur, dist[nextcur]));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        int a;
        for(int j = 1; j <= N; j++) {
            cin >> a;
            if(a == 1) {
                v[i].push_back(make_pair(j, a));
            }
        }
    }

    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        tmp.push_back(a);
    }

    dijkstra(tmp[0]);

    for(int i = 0; i < M; i++) {
        if(dist[tmp[i]] == INF) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}
