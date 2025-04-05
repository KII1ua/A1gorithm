#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define Endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
int arr[100001];
int dp[100001];

void solve() {

    for(int i = 1; i <= N; i++) {
        dp[i] = arr[i] + dp[i-1];
    }

    ll result = 0;

    for(int i = 1; i < N; i++) {
        result += (dp[N] - dp[i]) * arr[i];
    }

    cout << result;
}

void input() {
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
