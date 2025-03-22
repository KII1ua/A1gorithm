#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int A, K;
bool visited[1000001];

void bfs() {
    queue<pii> q;
    q.push(make_pair(A, 0));
    visited[A] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(x == K) {
            cout << cnt;
            return;
        }

        int xx[] = {x + 1, x * 2};

        for(int i = 0; i < 2; i++) {
            int nx = xx[i];

            if(nx >= 1 && nx <= 1000000) {
                if(!visited[nx]) {
                    q.push(make_pair(nx, cnt + 1));
                    visited[nx] = true;
                }
            }
        }
    }
}

void input() {
    cin >> A >> K;
}

void solution() {
    input();
    bfs();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solution();
}
