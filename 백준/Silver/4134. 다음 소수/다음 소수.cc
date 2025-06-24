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
int T;
ll n;

bool isprime(ll tmp) {

    if(tmp <= 1) return false;

    if(tmp == 2 || tmp == 3) return true;

    if(tmp % 2 == 0 || tmp % 3 == 0) return false;

    for(ll i = 5; i * i <= tmp; i++) {
        if(tmp % i == 0 || tmp % (i + 2) == 0) return false;
    }
    return true;
}

void solve() {
    ll stand = n;

    while(!isprime(stand)) {
        stand++;
    }

    cout << stand << endl;
}

void input() {
    cin >> T;

    while(T--) {
        cin >> n;

        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}