#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int T, X, Y;

void solve(int a, int b) {

    while(a != 1) {
        int x = b / a + 1;
        a = a * x - b;
        b = b * x;

        int tmp = gcd(a, b);
        a /= tmp, b /= tmp;
    }

    cout << b << endl;
}

void input() {
    cin >> T;

    while(T--) {
        cin >> X >> Y;
        solve(X, Y);
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
