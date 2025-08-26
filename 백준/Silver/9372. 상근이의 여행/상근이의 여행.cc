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

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int T, N, M;
vector<vector<int>> v(1001);
bool visited[1001];
int cnt;

void dfs(int Node) {
    visited[Node] = true;

    for(auto next : v[Node]) {
        if(!visited[next]) {
            cnt++;
            dfs(next);
        }
    }
}

void solve() {
    int answer = 0;
    cnt = 0;

    for(int i = 1; i <= N; i++) {
        dfs(i);
        answer += cnt;
        cnt = 0;
    }

    cout << answer << endl;
}

void input() {
    cin >> T;

    while(T--) {
        cin >> N >> M;

        memset(visited, 0, sizeof(visited));
        v.clear();
        v.resize(1001);

        for(int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
