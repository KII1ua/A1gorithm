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

int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int N, M;
int x = MAX;
int y = MAX;

void solve() {
    int tmp = M / N;

    for(int i = 1; i <= tmp; i++) {
        int a = i;
        int b;

        if(tmp % a == 0) {
            b = tmp / a;

            if(gcd(a * N, b * N) == N) {
                if (a + b < x + y) {
                    x = i;
                    y = b;
                }
            }
        }
    }

    cout << N * x << " " << N * y;
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