#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    string s;
    vector<int> v;
};

int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
int T, N, M, K, D;

void solve() {
    int ans = 0;
    int B = 1;

    while(true) {
        int A = B * K;
        int game = N * (M * (M-1) / 2) * A + N * M * (N-1) * M * B / 2;

        if(game <= D) {
            ans = max(ans, game);
            B++;
        }
        else break;
    }

    if(!ans) cout << -1 << endl;
    else cout << ans << endl;
}

void input() {
    cin >> T;

    for(int i = 0; i < T ;i++) {
        cin >> N >> M >> K >> D;

        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}