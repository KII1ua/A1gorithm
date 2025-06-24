#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
ll N;
ll mod = 1000000007;
unordered_map<ll, ll> um;

ll solve(ll n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    if(um.count(n) > 0) return um[n];

    if(n % 2 == 0) {
        ll m = n / 2;
        ll num1 = solve(m-1);
        ll num2 = solve(m);
        um[n] = ((2LL * num1 + num2) * num2) % mod;
        return um[n];
    }
    ll num1 = solve((n+1) / 2);
    ll num2 = solve((n-1) / 2);
    um[n] = ((1LL * num1 * num1) + (1LL * num2 * num2)) % mod;
    return um[n];
}

void input() {
    cin >> N;

    cout << solve(N);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}