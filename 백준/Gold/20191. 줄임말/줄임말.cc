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

struct horse {
    int x;
    int y;
    int dir;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string S, T;
vector<vector<int>> alpha(26);

void solve() {
    for(int i = 0; i < T.size(); i++) {
        alpha[T[i] - 'a'].push_back(i);
    }

    for(int i = 0; i < S.size(); i++) {
        if(alpha[S[i] - 'a'].empty()) {
            cout << -1;
            return;
        }
    }

    int idx = -1;
    int cnt = 1;

    for(int i = 0; i < S.size(); i++) {
        int stand = S[i] - 'a';
        int tmp = upper_bound(alpha[stand].begin(), alpha[stand].end(), idx) - alpha[stand].begin();

        if(tmp >= alpha[stand].size()) {
            i--;
            cnt++;
            idx = -1;
        }
        else {
            idx = alpha[stand][tmp];
        }
    }

    cout << cnt;
}

void input() {
    cin >> S >> T;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
