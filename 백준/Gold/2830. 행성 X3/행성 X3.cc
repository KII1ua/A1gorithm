#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e11

struct coordinate {
    int x;
    int y;
    int r;
};

struct halloween {
    int cnt;
    int score;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int bits[20];

void Print() {
    for(int i = 0; i < 20; i++) {
        cout << bits[i] << " ";
    }
}

void solve() {
    ll answer = 0;

    ll cnt = 1;
    for(int i = 0; i < 20; i++) {
        answer += (ll)bits[i] * (N - bits[i]) * cnt;
        cnt = cnt << 1;
    }

    cout << answer << endl;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;

        for(int i = 0; a != 0; i++) {
            if((a & 1)) {
                bits[i]++;
            }

            a = a >> 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
