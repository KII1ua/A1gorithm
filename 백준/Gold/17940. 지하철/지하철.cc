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
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
int arr[1001];
pii dist[1001];
vector<vector<pii>> v(1001);

void dijkstra() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    dist[0].first = 0;      // 환승
    dist[0].second = 0;     // 비용
    pq.push({0, 0, 0});     // 환승 횟수, 비용, 노드

    while(!pq.empty()) {
        int transfer = get<0>(pq.top());
        int cost = get<1>(pq.top());
        int Node = get<2>(pq.top());
        pq.pop();

        if(dist[Node].first < transfer || dist[Node].second < cost) continue;

        for(auto it : v[Node]) {
            int nextNode = it.first;
            int nextCost = cost + it.second;
            int nextTransfer = transfer + (arr[it.first] != arr[Node]);

            if(dist[nextNode].first >= nextTransfer) {
                if(dist[nextNode].second > nextCost) {
                    pq.push({nextTransfer, nextCost, nextNode});
                    dist[nextNode].first = nextTransfer;
                    dist[nextNode].second = nextCost;
                }
            }
        }
    }
}

void Print() {
    for(int i = 0; i < N; i++) {
        for(auto it : v[i]) {
            cout << it.first << " " << it.second << endl;
        }
        cout << endl;
    }
}

void solve() {
    dijkstra();

    cout << dist[M].first << " " << dist[M].second;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        dist[i].first = MAX;
        dist[i].second = MAX;
    }

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int a;
            cin >> a;

            if(a != 0) {
                v[i].push_back({j, a});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
