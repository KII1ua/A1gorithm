#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
int arr[100001];


void input() {
    while(true) {
        cin >> N >> M;

        if(N == 0 && M == 0) return;

        vector<int> board(N+1, 0);

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                cin >> arr[j];
            }

            vector<int> dp(M+1, 0);

            dp[1] = arr[1];

            for(int j = 2; j <= M; j++) {
                dp[j] = max(dp[j-1], dp[j-2] + arr[j]);
            }

            board[i] = dp[M];
        }

        for(int i = 1; i <= N; i++) {
            if(i >= 2) {
                board[i] = max(board[i-1], board[i-2] + board[i]);
            }
            else {
                board[i] = max(board[i], board[i-1]);
            }
        }

        cout << board[N] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}