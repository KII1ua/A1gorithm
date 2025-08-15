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

int dx[] = {0 ,0, -1, 0, 1, 1, -1, -1, 1};
int dy[] = {0, -1, 0, 1, 0, -1, 1, -1, 1};
int N, Q;
int arr[500001];
set<int> st;

void solve() {
    int idx = 1;

    for(int i = 0; i < Q; i++) {
        int a, b;
        cin >> a;

        if(a == 1) {
            cin >> b;
            if(st.find(b) != st.end()) {      // 존재하는 경우
                st.erase(b);
            }
            else st.insert(b);
        }
        else if(a == 2) {
            cin >> b;
            idx = (idx + b) % N;
            if(idx == 0) idx = N;
        }
        else {
            if(st.empty()) {
                cout << -1 << endl;
                continue;
            }
            
            auto left = st.lower_bound(idx);

            if(left == st.end()) {
                auto it = st.begin();
                cout << *it + (N - idx) << endl;
            }
            else {
                cout << *left - idx << endl;
            }
        }
    }
}

void input() {
    cin >> N >> Q;

    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        if(a == 1) st.insert(i);
    }

    solve();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
