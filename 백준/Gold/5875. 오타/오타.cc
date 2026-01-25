#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 100001;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string s;
int arr[MAX];
int dp[MAX];

void solve() {
    int left = 0;
    int right = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') left++;
        else right++;
    }

    if(left > right) {
        left = -1;
        right = 1;
    }
    else {
        left = 1;
        right = -1;
    }

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            arr[i] = left;
        }
        else arr[i] = right;
    }

    if(left == 1) {
        dp[0] = arr[0];
        int idx = 0;
        int ans = 0;
        if(dp[0] != -1) {
            for(int i = 1; i < s.size(); i++) {
                dp[i] = arr[i] + dp[i-1];

                if(dp[i] == -1) {
                    idx = i;
                    break;
                }
            }
        }

        for(int i = 0; i <= idx; i++) {
            if(s[i] == ')') ans++;
        }

        cout << ans;
    }
    else {
        dp[s.size()-1] = arr[s.size()-1];

        int idx = 0;
        int ans = 0;
        if(dp[s.size()-1] != -1) {
            for(int i = s.size()-2; i >= 0; i--) {
                dp[i] = arr[i] + dp[i+1];

                if(dp[i] == -1) {
                    idx = i;
                    break;
                }
            }
        }

        for(int i = s.size()-1; i >= idx; i--) {
            if(s[i] == '(') ans++;
        }

        cout << ans;
    }
}

void input() {
    cin >> s;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}