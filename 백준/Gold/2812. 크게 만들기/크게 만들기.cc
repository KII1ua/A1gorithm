// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N, K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;
    stack<int> st;

    cin >> N >> K;
    cin >> s;

    int cnt = K;

    for(int i = 0; i < N; i++) {
        int stand = s[i] - '0';

        while(!st.empty() && cnt > 0 && st.top() < stand) {
            cnt--;
            st.pop();
        }
        st.push(stand);
    }

    while(cnt > 0) {
        cnt--;
        st.pop();
    }

    string at = "";

    while(!st.empty()) {
        string res = to_string(st.top());
        at += res;
        st.pop();
    }

    reverse(at.begin(), at.end());

    cout << at;
}
