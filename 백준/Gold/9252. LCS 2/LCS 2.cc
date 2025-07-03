#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
};

struct Customer {
    int x;
    int y;
    int Dest_x;
    int Dest_y;
};

int dx[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};
//int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
//int dy[] = {0,0, -1, -1, -1, 0, 1, 1, 1};
//int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
//int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
string a, b;
int dp[1002][1002];

void Print() {
    
    
    for(int i = 1; i < b.length(); i++) {
        for(int j = 1; j < a.length(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    int N = b.length();
    int M = a.length();
    
    for(int i = 1; i < N; i++) {
        for(int j = 1; j < M; j++) {
            if(b[i] == a[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i = N-1;
    int j = M-1;

    stack<char> st;

    while(i > 0 && j >= 0) {
        if(b[i] == a[j]) {
            st.push(b[i]);
            i--;
            j--;
        }
        else {          // 같지 않은 경우 dp[i-1][j]와 dp[i][j-1]를 비교하여 같은 것으로 이동
            if(dp[i][j] == dp[i-1][j]) i--;
            else if(dp[i][j] == dp[i][j-1]) j--;
        }
    }

    cout << st.size() << endl;

    while(!st.empty()) {
        cout << (char)st.top();
        st.pop();
    }
}

void input() {
    cin >> a >> b;

    a.insert(0, "(");
    b.insert(0, ")");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}