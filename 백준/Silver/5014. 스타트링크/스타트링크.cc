// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int F, S, G, U, D;
int result = -1;
bool visited[1000001];

void bfs(int x, int y) {
    queue<pii> q;

    visited[x] = true;
    q.push(make_pair(x, y));

    while(!q.empty()) {
        int one = q.front().first;
        int two = q.front().second;
        q.pop();

        if(one == G) {
            result = two;
            return;
        }

        int dx[] = {one + U, one - D};

        for(int i = 0; i < 2; i++) {
            int nx = dx[i];

            if(nx > 0 && nx <= F) {
                if (!visited[nx]) {
                    visited[nx] = true;
                    q.push(make_pair(nx, two + 1));
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> F >> S >> G >> U >> D;

    bfs(S, 0);

    if(result == -1) {
        cout << "use the stairs";
        return 0;
    }

    cout << result;
}
