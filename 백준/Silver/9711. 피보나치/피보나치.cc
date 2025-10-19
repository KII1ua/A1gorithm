#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e18

struct coordinate {
    int x;
    int y;
    int r;
};

struct horse {
    int x;
    int y;
    int dir;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
ll T, P, Q;
ll arr[10002];

void solve(const int *cnt) {
    arr[1] = 1;
    arr[2] = 1;

    for(int i = 3; i <= P; i++) {
        arr[i] = (arr[i-1] + arr[i-2]) % Q;
    }

    cout << "Case #" << *cnt << ": " << arr[P] % Q << endl;
}

void input() {
    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> P >> Q;

        solve(&i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
