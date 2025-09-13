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

void solve() {
    ll x = 1;
    ll y = 1;

    while(true) {
        if((x + 1) * (y + 1) >= N) break;
        x++;
        if((x + 1) * (y + 1) >= N) break;
        y++;
    }

    cout << (x + y) * 2;
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
