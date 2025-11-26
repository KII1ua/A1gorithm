#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int arr[200001];

void solve() {
    int answer = 0;
    stack<int> st;

    for(int i = 0; i < N; i++) {
        while(!st.empty() && st.top() < arr[i]) {
            st.pop();
            answer++;
        }

        if(!st.empty()) answer++;

        st.push(arr[i]);
    }

    cout << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}