// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, result;
vector<int> v;
int dp[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        dp[i] = a;
    }

    for(int i = 0; i < N; i++) {
        for(int j = i-1; j >= 0; j--) {
            if(v[i] > v[j]) {
                dp[i] = max(dp[i], v[i] + dp[j]);
            }
        }
        result = max(result, dp[i]);
    }

    cout << result;
}
