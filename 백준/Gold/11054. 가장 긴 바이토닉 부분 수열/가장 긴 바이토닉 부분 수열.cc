#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
int arr[1001];
int dp1[1001];
int dp2[1001];
int result;

void solve() {

    for(int i = 0; i < N; i++) {
        dp1[i] = 1;
        for(int j = 0; j < N; j++) {
            if(arr[i] > arr[j] && dp1[j] + 1 > dp1[i]) {
                dp1[i] = dp1[j] + 1;
            }
        }
    }

    for(int i = N-1; i >= 0; i--) {
        dp2[i] = 1;
        for(int j = N-1; j > i; j--) {
            if(arr[i] > arr[j] && dp2[j] + 1 > dp2[i]) {
                dp2[i] = dp2[j] + 1;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(result < dp1[i] + dp2[i]) {
            result = max(result, dp1[i] + dp2[i]);
        }
    }

    cout << result - 1;
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
