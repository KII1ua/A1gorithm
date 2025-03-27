#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
int arr[1001];
int dp[1001];

void solve() {
    for(int i = 0; i < N; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(arr[i] < arr[j] && dp[j] + 1> dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    cout << *max_element(dp, dp+N);
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
