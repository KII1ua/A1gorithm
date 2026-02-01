#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 200001;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, K;
int arr[MAX];
int dp[MAX];
map<int, int> m;
ll answer;

void Print() {
    for(int i = 1; i <= N; i++) {
        cout << dp[i] << " ";
    }
}

void solve() {
    m[0] = 1;
    for(int i = 1; i <= N; i++) {
        dp[i] += dp[i-1] + arr[i];

        int value = dp[i] - K;
        answer += m[value];
        m[dp[i]]++;
    }

    cout << answer;
}

void input() {
    cin >> N >> K;

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