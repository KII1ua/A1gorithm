// baekjoon 24228
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int dp[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string a, b;

    cin >> a >> b;
    a = '(' + a;
    b = ')' + b;

    for(int i = 1; i < a.length(); i++) {
        for(int j = 1; j < b.length(); j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }


    cout << dp[a.length()-1][b.length()-1];
}
