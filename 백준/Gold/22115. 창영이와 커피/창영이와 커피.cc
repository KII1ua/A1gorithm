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

struct halloween {
    int cnt;
    int score;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, K;
int dp[100001];
int arr[101];

void solve() {
    for(int i = 1; i <= K; i++) {
        dp[i] = MAX;
    }

    for(int i = 0; i < N; i++) {
        for(int j = K; j >= arr[i]; j--) {
            dp[j] = min(dp[j], dp[j-arr[i]] + 1);
        }
    }

    cout << ((dp[K] == MAX)? -1 : dp[K]);
}

void input() {
    cin >> N >> K;

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
