#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int T, d, n;
ll arr[50002];
ll dp[1000001];

void solve() {
    for(int i = 1; i <= n; i++) {
        int idx = arr[i] % d;
        dp[idx]++;
    }

    ll answer = dp[0];

    for(int i = 0; i < d; i++) {
        ll cnt = dp[i];
        
        if(cnt > 1) {
            answer += (cnt * (cnt - 1)) / 2;
        }
    }

    cout << answer << endl;
}

void input() {
    cin >> T;

    while(T--) {
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        cin >> d >> n;

        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            arr[i] += arr[i-1];
        }

        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}