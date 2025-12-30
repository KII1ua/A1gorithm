#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string s;

void solve() {
    stack<char> st;

    for(int i = 0; i < s.size(); i++) {
        st.push(s[i]);

        if(st.size() >= 4 && s[i] == 'P') {

            string tmp = "";

            for(int j = 0; j < 4; j++) {
                char ch = st.top();
                st.pop();
                tmp += ch;
            }

            if(tmp == "PAPP") {
                tmp = "P";
            }

            for(int j = tmp.size() - 1; j >= 0; j--) {
                st.push(tmp[j]);
            }
        }
    }

    if(st.size() == 1 && st.top() == 'P') {
        cout << "PPAP";
    }
    else cout << "NP";
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