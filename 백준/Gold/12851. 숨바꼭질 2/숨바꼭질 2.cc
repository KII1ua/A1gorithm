// baekjoon 24228
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
bool visited[100001];
int N, K, second, result;

int bfs(int x) {        // 좌표
    queue<pair<int, int>> q;

    q.push({x, 0});
    visited[x] = true;

    while(!q.empty()) {
        int dx = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(dx == K) {
            return cnt;
        }

        int dst[] = {dx + 1, dx - 1, dx * 2};

        for(int i = 0; i < 3; i++) {
            int nx = dst[i];

            if(nx >= 0 && nx <= 100000 && !visited[nx]) {
                q.push({nx, cnt+1});
                visited[nx] = true;
            }
        }
    }
}

void bfs2(int x, int z) {     // 현재 위치, 0, 가장빠른 시간
    queue<pair<int, int>> q;

    q.push({x, 0});
    visited[x] = true;

    while(!q.empty()) {
        int dx = q.front().first;
        int cnt = q.front().second;
        visited[dx] = true;
        q.pop();

        if(dx == K && cnt == z) {
            result++;
        }

        int dst[] = {dx + 1, dx - 1, dx * 2};

        for(int i = 0; i < 3; i++) {
            int nx = dst[i];

            if(nx >= 0 &&!visited[nx] && nx <= 100000 && cnt <= z) {
                q.push({nx, cnt+1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    second = bfs(N);

    memset(visited, false, sizeof(visited));

    bfs2(N, second);

    cout << second << endl << result;
}
