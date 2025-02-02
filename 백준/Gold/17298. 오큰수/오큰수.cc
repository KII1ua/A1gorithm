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
stack<int> st;
int arr[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        arr[i] = a;

        if(st.empty()) st.push(i);
        else {
            if(arr[st.top()] < a) {
                while (!st.empty() && arr[st.top()] < a) {
                    arr[st.top()] = a;
                    st.pop();
                }
                st.push(i);
            }

            else {
                st.push(i);
            }
        }
    }

    while(!st.empty()) {
        arr[st.top()] = -1;
        st.pop();
    }

    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
}
