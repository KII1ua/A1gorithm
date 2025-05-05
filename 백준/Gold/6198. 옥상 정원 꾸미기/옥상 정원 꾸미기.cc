#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
vector<int> v;
ll result;

void solve() {
    stack<int> st;

    for(int i = 0; i < N; i++) {
        int stand = v[i];

        if(st.empty()) {
            st.push(stand);
        }
        else if(st.top() <= stand) {
            while(!st.empty() && st.top() <= stand) {
                st.pop();
            }
            st.push(stand);
        }
        else st.push(stand);

        result += st.size()-1;
    }

    cout << result;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}