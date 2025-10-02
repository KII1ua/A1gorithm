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

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
vector<string> v;
set<string> st;

bool check(string a, string b) {
    if(a.length() != b.length()) return false;

    for(int i = 0; i < b.length(); i++) {
        string str = b.substr(i, b.length()) + b.substr(0, i);

        if(a == str) {
            return true;
        }
    }
    return false;
}

void solve() {
    int cnt = 0;

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(check(v[i], v[j])) {
                v[j] = v[i];
                st.insert(v[i]);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        st.insert(v[i]);
    }

    cout << st.size();
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
