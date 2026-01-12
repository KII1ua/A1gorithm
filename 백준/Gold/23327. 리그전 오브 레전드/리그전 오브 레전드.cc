#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 123457;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, Q;
int arr[100001];
ll dp1[100001];     // 누적합 
ll dp2[100001];     // 제곱

void solve() {
    for(int i = 1; i <= N; i++) {
        dp1[i] = dp1[i-1] + arr[i];
    }

    for(int i = 1; i <= N; i++) {
        dp2[i] = dp2[i-1] + (arr[i] * arr[i]);
    }

    for(int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;

        ll answer = ((dp1[b] - dp1[a] + arr[a]) * (dp1[b] - dp1[a] + arr[a]) - (dp2[b] - dp2[a] + (arr[a] * arr[a]))) / 2;

        cout << answer << endl;
    }
}

void input() {
    cin >> N >> Q;

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