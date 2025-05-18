#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, M;
ll dp[99];

void solve() {
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= N; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[N];
}

void input() {
    cin >> N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}