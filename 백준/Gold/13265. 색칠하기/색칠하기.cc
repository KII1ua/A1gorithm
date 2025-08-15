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

struct nutrition {
    int p;
    int f;
    int s;
    int v;
    int cost;
};

int dx[] = {0 ,0, -1, 0, 1, 1, -1, -1, 1};
int dy[] = {0, -1, 0, 1, 0, -1, 1, -1, 1};
int T, N, M;
int visited[1001];
vector<vector<int>> v(1001);

bool bfs(int n) {        // 색깔 1, 2 사용
    queue<pii> q;
    q.push({n, 1});
    visited[n] = 1;

    while(!q.empty()) {
        int Node = q.front().first;
        int Color = q.front().second;
        q.pop();

        for(auto it : v[Node]) {
            int NextNode = it;

            if(Color == 1) {
                if(!visited[NextNode]) {        // 색깔이 칠해지지 않았을 때
                    q.push({NextNode, 2});
                    visited[NextNode] = 2;
                }
                else {
                    if(visited[NextNode] == 1) {
                        return false;
                    }
                }
            }
            else if(Color == 2) {
                if(!visited[NextNode]) {
                    q.push({NextNode, 1});
                    visited[NextNode] = 1;
                }
                else {
                    if(visited[NextNode] == 2) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

void solve() {
    bool check = false;
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            if(!bfs(i)) {
                check = true;
            }
        }
    }

    if(!check) {
        cout << "possible" << endl;
    }
    else cout << "impossible" << endl;
}

void input() {
    cin >> T;

    while(T--) {
        cin >> N >> M;

        memset(visited, 0, sizeof(visited));
        v.clear();
        v.resize(N+1);

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
