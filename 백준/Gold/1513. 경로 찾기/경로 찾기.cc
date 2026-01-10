#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 123457;
const int MOD = 1e6 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M, C;
int dp[53][53][53][53];     // x, y, 방문 횟수, 마지막 번호
int graph[51][51];

void solve() {
    if(graph[1][1] > 0) {       // 시작위치가 오락실이 있는 경우
        dp[1][1][1][graph[1][1]] = 1;
    }
    else {
        dp[1][1][0][0] = 1;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(i == 1 && j == 1) continue;
            for(int k = 0; k <= C; k++) {       // 오락실 방문 횟수
                for(int l = 0; l <= C; l++) {       // 마지막 오락실 번호

                    int count = 0;

                    if(i > 0) count = (count + dp[i-1][j][k][l]) % MOD;
                    if(j > 0) count = (count + dp[i][j-1][k][l]) % MOD;

                    if(count == 0) continue;

                    if(graph[i][j] == 0) {      // 오락실이 아닌 경우
                        dp[i][j][k][l] = (dp[i][j][k][l] + count) % MOD;
                    }
                    else {      // 오락실인 경우
                        if(graph[i][j] > l) {       // 마지막 방문 오락실보다 현재 오락실 번호가 커야함
                            dp[i][j][k+1][graph[i][j]] = (dp[i][j][k+1][graph[i][j]] + count) % MOD;
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i <= C; i++) {
        int answer = 0;
        for(int j = 0; j <= C; j++) {
            answer = (answer + dp[N][M][i][j]) % MOD;
        }
        cout << answer << " ";
    }
}

void input() {
    cin >> N >> M >> C;

    for(int i = 1; i <= C; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = i;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}