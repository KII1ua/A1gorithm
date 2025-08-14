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

int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};
int N, K;
int dist[501][501];
int dp[501][501];
vector<pii> v;

int manhatan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void Init() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= K; j++) {
            dp[i][j] = MAX;
        }
    }
}

void solve() {
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            int x1 = v[i].first;
            int y1 = v[i].second;
            int x2 = v[j].first;
            int y2 = v[j].second;

            dist[i][j] = manhatan(x1, y1, x2, y2);
        }
    }

    dp[0][0] = 0;
    for(int i = 1; i < N; i++) {
        dp[i][0] = dp[i-1][0] + dist[i-1][i];
    }

    for(int i = 0; i < N; i++) {            // 도착지
        for(int j = 0; j <= K; j++) {       // 건너뛰는 횟수
            for(int k = 0; k <= K; k++) {   // 이전까지 건너뛴 횟수
                if(i - 1 - k < 0)  continue;
                if(j - k < 0) continue;     // 건너뛴 횟수가 중간에 건너뛴 횟수보다 많은경우

                dp[i][j] = min(dp[i][j], dp[i -1 -k][j-k] + dist[i -1 -k][i]);
            }
        }
    }

    int result = MAX;

    for(int i = 0; i <= K; i++) {
        result = min(result, dp[N-1][i]);
    }

    cout << result;
}

void input() {
    cin >> N >> K;

    Init();

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
