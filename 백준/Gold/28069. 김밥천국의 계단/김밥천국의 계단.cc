#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e11

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int N, K;
int dp[1000001];

void solve() {
    fill(dp, dp + N+1, MAX);

    dp[0] = 0;

    for(int i = 0; i <= N; i++) {
        if(i + 1 <= N) {
            dp[i+1] = min(dp[i+1], dp[i] + 1);
        }
        if(i + i / 2 <= N) {
            dp[i + i / 2] = min(dp[i + i / 2], dp[i] + 1);
        }
    }

    if(dp[N] <= K) {
        cout << "minigimbob";
    }
    else cout << "water";
}

void input() {
    cin >> N >> K;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}