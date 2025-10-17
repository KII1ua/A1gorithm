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

struct horse {
    int x;
    int y;
    int dir;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
int arr[100001];
int dp[100002];

void solve() {
    for(int i = 1; i <= N; i++) {
        dp[i] += dp[i-1];

        cout << arr[i] + dp[i] << " ";
    }
}

void input() {
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < M; i++) {
        int a, b, k;
        cin >> a >> b >> k;
        dp[a] += k;
        dp[b+1] += -k;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
