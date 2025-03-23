#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M;
int arr[41];
ll dp[41];
ll result = 1;

void solve() {
    int cnt = 0;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= N; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    for(int i = 1; i <= N; i++) {
        if(arr[i] != -1) {
            cnt++;
        }
        else {
            result *= dp[cnt];
            cnt = 0;
        }
    }

    if(cnt >= 1) {
        result *= dp[cnt];
    }

    cout << result;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        arr[a] = -1;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
