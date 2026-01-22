#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 1000001;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int arr[MAX];
int dp1[MAX];
int dp2[MAX];

void solve() {
    dp1[0] = arr[0];
    dp2[N-1] = arr[N-1];

    for(int i = 1; i < N; i++) {
        dp1[i] = gcd(dp1[i-1], arr[i]);
    }

    for(int i = N-2; i >= 0; i--) {
        dp2[i] = gcd(dp2[i+1], arr[i]);
    }

    int maxvalue = -1;
    int rmvalue = -1;

    for(int i = 0; i < N; i++) {
        int value = 0;

        if(i == 0) {
            value = dp2[i+1];
        }
        else if(i == N-1) {
            value = dp1[i-1];
        }
        else {
            value = gcd(dp1[i-1], dp2[i+1]);
        }

        if(arr[i] % value != 0) {
            if(maxvalue < value) {
                maxvalue = value;
                rmvalue = arr[i];
            }
        }
    }

    if(maxvalue == -1) cout << -1;
    else cout << maxvalue << " " << rmvalue;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}