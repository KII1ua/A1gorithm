#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 20001;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int t, n, e;
int arr[101];
int dp[200001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--) {
        cin >> n >> e;

        memset(dp, -1, sizeof(dp));
        dp[0] = 0;

        int sum = 0;

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        for(int i = 0; i < n; i++) {
            for(int j = sum; j >= arr[i]; j--) {
                if(dp[j - arr[i]] >= 0) {
                    dp[j] = max(dp[j], dp[j - arr[i]] + 2 * arr[i]);
                }
            }
        }

        int answer = -1;

        for(int i = 0; i <= sum; i++) {
            if(dp[i] >= e) {
                answer = i;
                break;
            }
        }

        if(answer == -1) {
            cout << "FULL" << endl;
        }
        else cout << answer << endl;
    }
}