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

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
map<ll, ll> m;

ll solve(ll n) {
    if(m.count(n) > 0) return m[n];

    if(n % 2 == 0) {
       m[n] = (n / 2) * (n / 2) + (solve(n / 2) + solve(n / 2));
    }
    else m[n] = (n / 2) * (n / 2 + 1) + solve(n / 2) + solve(n / 2 + 1);

    return m[n];
}

void input() {
    cin >> N;

    m[1] = 0;

    cout << solve(N);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
