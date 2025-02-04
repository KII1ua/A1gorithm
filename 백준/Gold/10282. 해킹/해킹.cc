// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int T, n, d, c;
vector<vector<pii>> v(10001);
int dist[10001];

void dijkstra(int start) {
    int cnt = 0, time = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i = 1; i <= n; i++) {
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

    for(int i = 1; i <= n; i++) {
        if(dist[i] != INF) {
            cnt++;
            time = max(time, dist[i]);
        }
    }

    cout << cnt << " " << time << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;

    for(int l = 0; l < T; l++) {
        cin >> n >> d >> c;     // 컴퓨터 개수, 의존성 개수, 해킹당한 컴퓨터

        for(int k = 0; k < d; k++) {
            int a, b, s;
            cin >> a >> b >> s;
            v[b].push_back(make_pair(a, s));        // 도착지, 비용
        }

        dijkstra(c);
        for(int i = 1; i <= n; i++) {
            v[i].clear();
        }
    }
}
