#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
    int r;
};

struct halloween {
    int cnt;
    int score;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M, A, D;
int arr[2100];
int dp[2100][2100];     // 헌혈을 i번 했을때 날짜가 j까지고 누적 가산점 value

void Print() {
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N+D; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    for(int j = 1; j <= N; j++) {
        dp[0][j] = dp[0][j-1] + arr[j];
        
        if(dp[0][j] >= M) {
            cout << 0;
            return;
        }
    }

    for(int i = 1; i <= N; i++) {       // 헌혈 횟수
        for(int j = 1; j < N+D; j++) {
            if(j < D) continue;

            dp[i][j] = max(dp[i][j-1] + arr[j], dp[i-1][j-D] + A);

            if(dp[i][j] >= M) {
                cout << i;
                return;
            }
        }
    }

    cout << -1;
}

void input() {
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    cin >> A >> D;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
