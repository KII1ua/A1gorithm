#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, L, R, X, result;
vector<int> v;

void solve() {

    for(int i = 1; i < (1 << N); i++) {
        int level = 0;
        int easy = MAX, hard = 0;

        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) {
                level += v[j];
                easy = min(easy, v[j]);
                hard = max(hard, v[j]);
            }
        }

        if(hard - easy >= X && level >= L && level <= R) {
            result++;
        }
    }

    cout << result;
}

void input() {
    cin >> N >> L >> R >> X;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}