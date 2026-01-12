#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 123457;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int arr[2001];
int dp1[2001];      // 앞(무거움)
int dp2[2001];      // 뒤(가벼움)

void solve() {
    int answer = 0;

    for(int i = N-1; i >= 0; i--) {
        dp1[i] = 1;
        dp2[i] = 1;

        for(int j = i + 1; j < N; j++) {
            if(arr[i] < arr[j]) dp1[i] = max(dp1[i], dp1[j] + 1);

            if(arr[i] > arr[j]) dp2[i] = max(dp2[i], dp2[j] + 1);
        }
        answer = max(answer, dp1[i] + dp2[i] - 1);
    }

    cout << answer;
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