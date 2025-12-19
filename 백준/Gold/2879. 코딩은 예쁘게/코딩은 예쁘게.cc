#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int arr[1001];
int indent[1001];
int dp[1001];

void solve() {
    for(int i = 0; i < N; i++) {
        dp[i] = arr[i] - indent[i];
    }

    int answer = abs(dp[0]);

    for(int i = 1; i < N; i++) {
        if(dp[i] * dp[i-1] < 0) {
            answer += abs(dp[i]);
        }
        else {
            if(abs(dp[i]) > abs(dp[i-1])) {
                answer += abs(dp[i] - dp[i-1]);
            }
        }
    }

    cout << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> indent[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}