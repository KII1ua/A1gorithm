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
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
string s;
int arr[200001];
stack<int> st;

void solve() {
    for(int i = 0; i < N; i++) {
        if(s[i] == '(') st.push(i);
        else if(st.size()) {
            arr[i] = arr[st.top()] = 1;
            st.pop();
        }
    }

    int answer = 0;
    int cnt = 0;

    for(int i = 0; i < N; i++) {
        if(arr[i]) {
            cnt++;
            answer = max(cnt, answer);
        }
        else {
            cnt = 0;
        }
    }

    cout << answer;
}

void input() {
    cin >> N >> s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
