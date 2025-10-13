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

struct horse {
    int x;
    int y;
    int dir;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};
int N;
int dp[1000001];

void Print() {
    for(int i = 1; i <= N; i++) {
        cout << dp[i] << " ";
    }
}

void solve() {
    dp[1] = 0;

    for(int i = 2; i <= N; i++) {
        dp[i] = dp[i-1] + 1;
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);

        if(i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    int tmp = N;
    vector<int> v;
    v.push_back(tmp);

    cout << dp[N] << endl;

    while(tmp != 1) {
        if(tmp % 3 == 0 && dp[tmp / 3] < dp[tmp]) {
            v.push_back(tmp / 3);
            tmp /= 3;
            continue;
        }

        if(tmp % 2 == 0 && dp[tmp / 2] < dp[tmp]) {
            v.push_back(tmp / 2);
            tmp /= 2;
            continue;
        }

        v.push_back(tmp - 1);
        tmp--;
    }

    for(auto it : v) {
        cout << it << " ";
    }
}

void input() {
    cin >> N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
