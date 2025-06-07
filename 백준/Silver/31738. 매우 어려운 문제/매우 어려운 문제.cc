#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e8

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
ll N, M;

void solve() {
    if(N < M) {
        ll a = 1;

        for(int i = 2; i <= N; i++) {
            a = (a * i) % M;
        }

        cout << a % M;
    }
    else {
        cout << 0;
    }
}

void input() {
    cin >> N >> M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}