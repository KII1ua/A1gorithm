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

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
string s;
stack<ll> st;

void solve() {
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 48) {
            st.push(s[i] - '0');
        }
        else {
            ll a, b;
            for(int j = 0; j < 2; j++) {
                if(j == 0) b = st.top();
                else if(j == 1) a = st.top();
                st.pop();
            }

            if(s[i] == '+') {
                st.push(a + b);
            }
            else if(s[i] == '-') {
                st.push(a - b);
            }
            else if(s[i] == '*') {
                st.push(a * b);
            }
            else st.push(a / b);
        }
    }

    while(!st.empty()) {
        cout << st.top();
        st.pop();
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