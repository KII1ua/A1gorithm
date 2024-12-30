// baekjoon 1012
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, M, num;
int dp[MAX][MAX];

bool compare(string a, string b) {
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int x1, y1, x2, y2;

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> num;
            dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + num;
        }
    }

    for(int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - (dp[x1-1][y2] + dp[x2][y1-1]) + dp[x1-1][y1-1] << endl;
    }
}