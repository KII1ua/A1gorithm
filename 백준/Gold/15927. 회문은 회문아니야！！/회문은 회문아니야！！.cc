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
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};
int dx[] = {1, 0};
int dy[] = {0, 1};
string s;
set<char> st;

void solve() {
    for(int i = 0; i < s.size(); i++) {
        st.insert(s[i]);
    }

    string tmp = s;
    reverse(tmp.begin(), tmp.end());

    if(s != tmp) {
        cout << s.size();
    }
    else if(st.size() == 1) {
        cout << -1;
    }
    else {
        cout << s.size() - 1;
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
