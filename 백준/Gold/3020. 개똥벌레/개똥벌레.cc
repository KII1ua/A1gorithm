#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 200001;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, H;
int jongyu[MAX];
int seoksun[MAX];
int dp[500002];

void solve() {
    for(int i = 0; i < N / 2; i++) {
        int left = 1;
        int right = seoksun[i]+1;
        dp[left] += 1;
        dp[right] -= 1;
    }

     for(int i = 0; i < N / 2; i++) {
         int left = H - jongyu[i] + 1;
         int right = H+1;
         dp[left] += 1;
         dp[right] -= 1;
     }

    for(int i = 1; i <= H; i++) {
        dp[i] += dp[i-1];
    }

    int cnt = INF;
    int count = 0;

    for(int i = 1; i <= H; i++) {
        if(cnt >= dp[i]) {
            if(cnt == dp[i]) count++;
            else {
                cnt = dp[i];
                count = 1;
            }
        }
    }

    cout << cnt << " " << count;
}

void input() {
    cin >> N >> H;

    int idx1 = 0;
    int idx2 = 0;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if(i % 2 == 0) {
            seoksun[idx1++] = a;
        }
        else jongyu[idx2++] = a;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}