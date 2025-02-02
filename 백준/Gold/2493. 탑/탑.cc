// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
stack<pii> st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;

        if(st.empty()) {
            st.push(make_pair(i, a));
            cout << "0 ";
        }
        else {
            while(!st.empty()) {
                if(st.top().second > a) {   // 송신할 수 있는 경우
                    cout << st.top().first << " ";
                    break;
                }
                else {      // 송신할 수 없는 경우
                    st.pop();
                }
            }

            if(st.empty()) cout << "0 ";
            st.push(make_pair(i, a));
        }
    }
}
