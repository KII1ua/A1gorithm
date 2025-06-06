#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M, R;
vector<vector<int>> v(100001);
int visited[100001];
int cnt = 1;

bool compare(int a, int b) {
    return a > b;
}

void bfs() {
    queue<int> q;
    q.push(R);
    visited[R] = cnt;
    cnt++;

    while(!q.empty()) {
        int xx = q.front();
        q.pop();

        for(int i = 0; i < v[xx].size(); i++) {
            int nx = v[xx][i];

            if(visited[nx] == 0) {
                q.push(nx);
                visited[nx] = cnt;
                cnt++;
            }
        }
    }
}

void solve() {
    bfs();

    for(int i = 1; i <= N; i++) {
        cout << visited[i] << endl;
    }
}

void input() {
    cin >> N >> M >> R;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 1; i <= N; i++) {
        sort(v[i].begin(), v[i].end(), compare);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}