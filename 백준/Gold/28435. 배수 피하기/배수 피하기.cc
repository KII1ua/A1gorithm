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
int N, K;
int arr[100001];

ll fpow(ll base, ll exp) {
    ll ans = 1;

    while(exp > 0) {
        if(exp % 2 == 1) {
            ans = (ans * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }

    return ans;
}

void solve() {
    ll answer = 1;

    answer = answer * (arr[0] + 1);

    for(int i = 1; i < K - i; i++) {
        ll a = fpow(2, arr[i]);
        ll b = fpow(2, arr[K-i]);

        ll tmp = (a + b - 1 % MOD) % MOD;
        answer = answer * tmp % MOD;
    }

    if(K % 2 == 0) {
        answer = answer * (arr[K / 2] + 1) % MOD;
    }

    answer = (answer - N - 1 + MOD) % MOD;

    cout << answer;
}

void input() {
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        arr[a % K]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}