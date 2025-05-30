#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int N, P, K;
vector<vector<pii>> v(1001);
int dist[1001];

bool dijkstra(int mid) {
    for(int i = 1; i <= N; i++) {
        dist[i] = MAX;
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(1, 0));    // 정점, 비용
    dist[1] = 0;

    while(!pq.empty()) {
        int current = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if(dist[current] < cost) continue;

        for(auto it : v[current]) {
            int nextcur = it.first;
            int accurcost = cost + (it.second > mid);

            if(dist[nextcur] > accurcost) {
                pq.push(make_pair(nextcur, accurcost));
                dist[nextcur] = accurcost;
            }
        }
    }

    return dist[N] <= K;
}

void solve() {
    int s = 0;
    int e = MAX;
    int result = -1;

    while(s <= e) {
        int mid = (s + e) / 2;

        if(dijkstra(mid)) {
            result = mid;
            e = mid-1;
        }
        else s = mid+1;
    }

    cout << result;
}

void input() {
    cin >> N >> P >> K;

    for(int i = 0; i < P; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}