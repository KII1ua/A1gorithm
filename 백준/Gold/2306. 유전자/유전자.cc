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
int dp[501][501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s;

    cin >> s;

    int answer = 0;

    for(int l = 1; l <= s.size(); l++) {     // 문자 길이
        for(int i = 0; i + l -1 < s.size(); i++) {     // 시작점
            int j = i + l - 1;      // 끝점

            if((s[i] == 'a' && s[j] == 't') || (s[i] == 'g' && s[j] == 'c')) {
                dp[i][j] = max(dp[i][j], dp[i+1][j-1]+2);
                answer = max(answer, dp[i][j]);
            }

            for(int k = i; k < j; k++) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j]);
                answer = max(answer ,dp[i][j]);
            }
        }
    }

    cout << answer;
}