// baekjoon 1504
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int dist[1001];
int route[1001];
vector<vector<pii>> v(1001);
vector<int> rv;
int N, M;

void dijkstra(int x) {
    for(int i = 1; i <= N; i++) {
        dist[i] = INF;
    }

    dist[x] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push(make_pair(x, dist[x]));

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
                route[nextcur] = cur;
                pq.push(make_pair(nextcur, dist[nextcur]));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int a, b, c, start, end;

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }

    cin >> start >> end;

    dijkstra(start);

    cout << dist[end] << endl;

    int temp = end;

    while(temp) {
        rv.push_back(temp);
        temp = route[temp];
    }

    cout << rv.size() << endl;

    for(int i = rv.size() - 1; i >= 0; i--) {
        cout << rv[i] << " ";
    }
}