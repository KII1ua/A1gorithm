#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 200001;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, T;
vector<pii> v;
vector<vector<int>> graph(MAX);
bool visited[50001];

void bfs() {
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});

    while(!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        q.pop();

        if(y == T) {
            cout << cnt;
            exit(0);
        }

        for(auto &iter : graph[y]) {
            int nx = v[iter].first;
            int ny = v[iter].second;

            if(!visited[iter] && abs(nx - x) <= 2) {
                q.push({nx, ny, cnt+1});
                visited[iter] = true;
            }
        }
    }
}

void solve() {
    bfs();

    cout << -1;
}

void input() {
    cin >> N >> T;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for(int i = 0; i < N; i++) {
        int y = v[i].second;

        for(int j = y; j >= y - 2; j--) {
            if(j >= 0) {
                graph[j].push_back(i);
            }
        }

        for(int j = y; j <= y + 2; j++) {
            if(j < MAX) {
                graph[j].push_back(i);
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