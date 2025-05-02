#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, M, R;
ll di[100001];     // 노드의 깊이
ll ti[100001];     // 노드 방문순서
bool visited[100001];
vector<vector<int>> v(100001);
ll result;

void bfs(int start) {
    queue<int> q;
    int cnt = 1;
    q.push(start);
    visited[start] = true;
    di[start] = 0;
    ti[start] = cnt;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int i = 0; i < v[x].size(); i++) {
            int nx = v[x][i];

            if(!visited[nx]) {
                cnt++;
                q.push(nx);
                visited[nx] = true;
                di[nx] = di[x] + 1;
                ti[nx] = cnt;
            }
        }
    }
}

void solve() {
    for(int i = 1; i <= N; i++) {
        sort(v[i].begin(), v[i].end());
    }

    fill(di, di + 100001, -1);
    bfs(R);

    for(int i = 1; i <= N; i++) {
        result += di[i] * ti[i];
    }

    cout << result;
}

void input() {
    cin >> N >> M >> R;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}