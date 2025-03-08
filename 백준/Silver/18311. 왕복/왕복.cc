// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N;
int arr[100001];
ll K;

void input() {
    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

void solve() {
    for(int i = 1; i <= N; i++) {
        K -= arr[i];
        if(K < 0) {
            cout << i;
            return;
        }
    }

    for(int i = N; i >= 1; i--) {
        K -= arr[i];
        if(K < 0) {
            cout << i;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
