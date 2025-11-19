#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e15

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
int N, M, D, E;
ll up[100001];
ll down[100001];
int height[100001];
vector<vector<pii>> v(100001);


void downdijkstra(int start) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    down[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        ll cost = pq.top().first;
        int Node = pq.top().second;
        pq.pop();

        if(down[Node] < cost) continue;

        for(auto it : v[Node]) {
            int nextNode = it.first;
            ll nextCost = it.second + cost;

            if(height[Node] < height[nextNode] && down[nextNode] > nextCost) {
                pq.push({nextCost, nextNode});
                down[nextNode] = nextCost;
            }
        }
    }
}

void updijkstra(int start) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    up[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        ll cost = pq.top().first;
        int Node = pq.top().second;
        pq.pop();

        if(up[Node] < cost) continue;

        for(auto it : v[Node]) {
            int nextNode = it.first;
            ll nextCost = it.second + cost;

            if(height[Node] < height[nextNode] && up[nextNode] > nextCost) {
                pq.push({nextCost, nextNode});
                up[nextNode] = nextCost;
            }
        }
    }
}

void Print() {
    for(int i = 1; i <= N; i++) {
        cout << up[i] << " ";
    }
    cout << endl;

    for(int i = 1; i <= N; i++) {
        cout << down[i] << " ";
    }
}

void solve() {
    fill(up, up+N+1, MAX);
    fill(down, down+N+1, MAX);
    updijkstra(1);
    downdijkstra(N);

    ll answer = -MAX;

    for(int i = 2; i < N; i++) {
        if(up[i] == MAX || down[i] == MAX) continue;
        else {
            ll happy = height[i] * E;
            ll dist = (up[i] + down[i]) * D;

            answer = max(answer, happy - dist);
        }
    }

    if(answer == -MAX) {
        cout << "Impossible";
        return;
    }
    cout << answer;
}

void input() {
    cin >> N >> M >> D >> E;

    for(int i = 1; i <= N; i++) {
        cin >> height[i];
    }

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
