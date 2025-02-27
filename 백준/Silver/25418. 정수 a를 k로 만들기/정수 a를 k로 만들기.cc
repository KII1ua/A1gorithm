// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int A, K;
bool visited[1000001];

void bfs(int a) {
    queue<pii> q;

    q.push(make_pair(a, 0));
    visited[a] = true;

    while(!q.empty()) {
        int res = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(res == K) {
            cout << cnt;
            return;
        }

        int arr[] = {res + 1, res * 2};

        for(int i = 0; i < 2; i++) {
            int stand = arr[i];

            if(stand >= 1 && stand <= 1000000) {
                if(!visited[stand]) {
                    q.push(make_pair(stand, cnt+1));
                    visited[stand] = true;
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
    bfs(A);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solution();
}
