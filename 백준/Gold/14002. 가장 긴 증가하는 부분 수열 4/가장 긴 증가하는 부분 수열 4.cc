// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, result;
vector<int> v;
stack<int> st;
int dp[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int maxlen = 0;
    int maxidx = 0;
    int tmp = 1;

    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    fill(dp, dp + N, 1);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }


    for(int i = 0; i < N; i++) {
        if(dp[i] > maxlen) {
            maxlen = dp[i];
            maxidx = i;
        }
    }

    cout << maxlen << endl;
    st.push(v[maxidx]);
    maxlen--;
    for(int i = maxidx - 1; i >= 0; i--) {
        if(dp[i] == maxlen) {
            st.push(v[i]);
            maxlen--;
            tmp++;
        }
    }

    while(!st.empty()) {
        int result = st.top();
        cout << result << " ";
        st.pop();
    }
}
