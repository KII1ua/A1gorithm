#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
int arr[50001];
int prefix[50001];
int dp[4][50001];

void Print() {
    for(int i = 1; i <= N; i++) {
        cout << prefix[i] << " ";
    }

    cout << endl << endl;

    for(int i = 1; i < 4; i++) {
        for(int j = 1; j <= N; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
}

void solve() {
    for(int i = 1; i < 4; i++) {
        for(int j = 1; j <= N; j++) {
            if(j - M >= 0) {
                dp[i][j] = max({dp[i-1][j-M] + prefix[j] - prefix[j-M], dp[i-1][j], dp[i][j-1]});
            }
        }
    }

    cout << dp[3][N];
}

void input() {
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        prefix[i] = arr[i] + prefix[i-1];
    }

    cin >> M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}