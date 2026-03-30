#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int left, right;
};

const int INF = 1e9;
const int MAX = 100001;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int T, N;
int arr[502];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> N;

        vector<vector<int>> dp(N+1, vector<int>(N+1, INF));
        vector<vector<int>> cost(N+1, vector<int>(N+1, 0));

        for(int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        for(int i = 1; i <= N; i++) {
            for(int j = i; j <= N; j++) {
                if(i == j) {
                    cost[i][j] = arr[i];
                }
                else {
                    cost[i][j] = cost[i][j-1] + arr[j];
                }
            }
        }

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(i==j) dp[i][j] = 0;
            }
        }

        for(int len = 1; len < N; len++) {      // 길이
            for(int i = 1; i <= N - len; i++) {        // 시작점
                int j = i + len;
                for(int k = i; k < j; k++) {    // 끝점
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + cost[i][j]);
                }
            }
        }

        cout << dp[1][N] << endl;
    }
}