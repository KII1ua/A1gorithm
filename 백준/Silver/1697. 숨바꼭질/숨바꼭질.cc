// baekjoon 4889
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, K;
bool visited[100001];

int bfs(int a, int b) {
    queue<pair<int, int>> q;

    q.push({a, b});
    visited[a] = true;

    while(!q.empty()) {
        int dist = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(dist == K) {
            return cnt;
        }

        int dx[3] = {dist-1, dist+1, dist*2};

        for(int i = 0; i < 3; i++) {
            int nx = dx[i];
            if(nx >= 0 && nx <= 100000 && !visited[nx]) {
                visited[nx] = true;
                q.push({nx, cnt+1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    cin >> N >> K;

    cout << bfs(N, 0);
}