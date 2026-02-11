#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 1000001;
const int MOD = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
ll dp[MAX];
/*
    N명의 사람이 있을때 ex) A, B, C, D라고 가정
    A가 B우산을 가졌을때 
    1. B가 A우산을 가져가는 경우
    2. B가 A우산을 가져가지 않는 경우로 나눌 수 있다.

    이때 1번은 서로 다른 우산을 가져가며 마치 처음부터 A와 B가 없는 경우랑 같기 때문에 dp[n-2]와 같다
    2번은 A만 마치 없었던 경우랑 같기 때문에 dp[n-1]과 같다.

    이때 A를 기준으로 B의 우산을 가지는 경우를 생각했기에 C, D ... 등 모든 경우의 수를 구한다면 (n-1) * dp[n-2] + dp[n-1] 과 같다.
*/

void solve() {
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i <= N; i++) {
        dp[i] = ((i-1) * (dp[i-1] + dp[i-2])) % MOD;
    }

    cout << dp[N];
}

void input() {
    cin >> N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}