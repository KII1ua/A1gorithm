#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int T, N;
ll result;
int arr[1001];
ll dp[1001][1001];

void solve() {
    result = -MAX;

    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j++) {
            dp[i][j] = dp[i][j-1] + arr[j];
            result = max(result, dp[i][j]);
        }
    }

    cout << result << endl;
}

void input() {
    cin >> T;

    while(T--) {
        cin >> N;
        memset(dp, 0, sizeof(dp));
        memset(arr, 0, sizeof(arr));

        for(int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}