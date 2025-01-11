// baekjoon 3968            unorder_map은 해시테이블 기반으로 insert, erase, find가 O(1)으로 수행된다.
#include <bits/stdc++.h>  // but map은 레드블랙트리를 기반으로 하여 실행 시간이 O(log N)이 된다.
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, K;
ll dp[201][201];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
        dp[1][i] = 1;
    }

    for(int j = 1; j <= K; j++) {
        dp[j][1] = j;
    }

    for(int i = 2; i <= K; i++) {
        for(int j = 2; j <= N; j++) {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 1000000000;
        }
    }

    cout << dp[K][N] % 1000000000;
}
