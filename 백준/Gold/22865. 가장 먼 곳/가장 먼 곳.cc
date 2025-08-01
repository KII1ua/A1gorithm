#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    string s;
    vector<int> v;
};

int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
int N, M, result;
vector<vector<pii>> v(100001);
int dist[100001];
vector<int> locate;
map<int, vector<int>> m;
set<int> st;
int gaps;

void dijkstra(int a) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, a});
    dist[a] = 0;

    while(!pq.empty()) {
        int Node = pq.top().second;
        int Cost = pq.top().first;
        pq.pop();

        if(dist[Node] < Cost) continue;

        for(auto it : v[Node]) {
            int NextNode = it.first;
            int NextCost = Cost + it.second;

            if(dist[NextNode] > NextCost) {
                pq.push({NextCost, NextNode});
                dist[NextNode] = NextCost;
            }
        }
    }
    for(int i = 1; i <= N; i++) {       // key
        if(st.count(i) > 0) continue;
        m[i].push_back(dist[i]);
    }
}

void Init() {
    for(int i = 1; i <= N; i++) {
        dist[i] = MAX;
    }
}

void solve() {
    for(auto it : locate) {
        Init();
        dijkstra(it);
    }

    for(auto it : m) {
        int x = it.first;
        vector<int> tmp = it.second;
        int gap = MAX;

        for(auto iter : tmp) {
            if(gap > iter) {
                gap = iter;
            }
        }
        if(gaps < gap) {
            result = x;
            gaps = gap;
        }
    }

    cout << result;
}

void input() {
    cin >> N;

    for(int i = 0; i < 3; i++) {
        int a;
        cin >> a;
        locate.push_back(a);
        st.insert(a);
    }

    cin >> M;

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