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
int N, K;
int graph[5001];
bool visited[5001];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        if(x == N) {
            cout << "YES";
            exit(0);
        }

        for(int i = 1; i <= N-x; i++) {
            int xx = x + i;
            ll yy = (xx - x) * (1 + abs(graph[x] - graph[xx]));

            if(!visited[xx] && yy <= K) {
                q.push(xx);
                visited[xx] = true;
            }
        }
    }
}

void solve() {
    bfs(1);

    cout << "NO";
}

void input() {
    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
        cin >> graph[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}