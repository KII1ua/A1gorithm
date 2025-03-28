#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {0,-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0,0, 0, -1, 1, -1, 1, -1, 1};
int T;
bool visited[600];

void bfs(int x) {
    queue<pii> q;
    q.push(make_pair(x, 0));
    visited[x] = true;

    while(!q.empty()) {
        int sz = q.size();

        while(sz--) {
            int xx = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if(!xx) {
                cout << cnt << endl;
                return;
            }

            for(int i = 0; i < 9; i++) {
                int ax = i / 3;
                int ay = i % 3;
                int stand = xx;

                for(int j = 0; j < 5; j++) {
                    int nx = ax + dx[j];
                    int ny = ay + dy[j];

                    if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                        stand ^= (1 << (nx * 3 + ny));
                    }
                }
                if(!visited[stand]) {
                    q.push(make_pair(stand, cnt+1));
                    visited[stand] = true;
                }
            }
        }
    }
}

void input() {
    cin >> T;

    while(T--) {
        int val = 0;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                char a;
                cin >> a;
                if(a == '*') val |= (1 << (i * 3 + j));
            }
        }

        bfs(val);
        memset(visited, 0, sizeof(visited));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
