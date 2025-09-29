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

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
int arr[] = {7, 5, 2, 1};
int dp[100001];

void solve() {
    fill(dp, dp+N+1, MAX);
    dp[0] = 0;

    for(int i = 1; i <= N; i++) {
        for(auto it : arr) {
            if(i - it >= 0) {
                dp[i] = min(dp[i-it] + 1, dp[i]);
            }
        }
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
