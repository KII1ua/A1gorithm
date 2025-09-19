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
int N, M;
vector<vector<int>> v(11);

void solve() {
    int answer = MAX;

    for(int i = 0; i < (1 << M); i++) {
        set<int> st;
        int cnt = 0;
        for(int j = 0; j < M; j++) {
            if(i & (1 << j)) {
                for(int k = 0; k < v[j].size(); k++) {
                    st.insert(v[j][k]);
                }
                cnt++;
            }
        }

        bool flag = false;
        for(int j = 1; j <= N; j++) {
            if(st.find(j) == st.end()) {
                flag = true;
                break;
            }
        }

        if(!flag) {
            answer = min(answer, cnt);
        }
    }

    if(answer == MAX) cout << -1;
    else cout << answer;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        for(int j = 0; j < a; j++) {
            int b;
            cin >> b;
            v[i].push_back(b);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
