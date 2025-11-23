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
string a, b;
int dp[42][42];

void Print() {
    for(int i = 1; i < a.size(); i++) {
        for(int j = 1; j < b.size(); j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
}

void solve() {
    a.insert(0, "0");
    b.insert(0, "1");

    for(int i = 1; i < a.size(); i++) {
        for(int j = 1; j < b.size(); j++) {
            if(a[i] == b[j]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string ans = "";

    int i = a.size()-1;
    int j = b.size()-1;

    while(i > 0 && j > 0) {
        if(dp[i][j] == dp[i-1][j]) {
            i--;
        }
        else if(dp[i][j] == dp[i][j-1]) {
            j--;
        }
        else {
            ans += a[i];
            i--, j--;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}

void input() {
    cin >> a >> b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
