#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int arr[100001];
int cnt[100001];
int building[100001];

void Print() {
    for(int i = 1; i <= N; i++) {
        cout << cnt[i] << " ";
    }

    cout << endl;

    for(int i = 1; i <= N; i++) {
        cout << building[i] << " ";
    }
}

void solve() {
    stack<int> st;

    for(int i = 1; i <= N; i++) {
        if(st.empty()) {
            st.push(i);
            continue;
        }
        else if(!st.empty() && arr[st.top()] <= arr[i]) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
        }

        if(!st.empty() && arr[st.top()] > arr[i]) {
            building[i] = st.top();
        }

        cnt[i] += st.size();

        st.push(i);
    }

    while(!st.empty()) {
        st.pop();
    }

    for(int i = N; i >= 1; i--) {
        if(st.empty()) {
            st.push(i);
            continue;
        }
        else if(!st.empty() && arr[st.top()] <= arr[i]) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
        }

        if(!st.empty()) {
            if(building[i] == 0 || abs(i - building[i]) > abs(i - st.top())) {
                building[i] = st.top();
            }
        }

        cnt[i] += st.size();

        st.push(i);
    }

    for(int i = 1; i <= N; i++) {
        if(cnt[i] > 0) {
            cout << cnt[i] << " " << building[i] << endl;
        }
        else cout << 0 << endl;
    }
}

void input() {
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}