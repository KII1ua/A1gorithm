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
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};
vector<pair<int, string>> v;
int N, M, K;
map<string, int> m;
set<string> st;

void solve() {
    int answer = 0;

    for(int i = 0; i < K; i++) {
        string s;
        cin >> s;
        st.insert(s);
        answer += m[s];
    }

    int ans_max = answer;
    int ans_min = answer;
    int cnt = M - K;

    sort(v.begin(), v.end());

    set<string> tmp = st;

    for(int i = 0; i < N; i++) {
        if(cnt <= 0) break;
        string title = v[i].second;
        int score = v[i].first;

        if(tmp.find(title) == tmp.end()) {
            tmp.insert(title);
            ans_min += score;
            cnt--;
        }
    }

    tmp = st;
    cnt = M - K;

    for(int i = N-1; i >= 0; i--) {
        if(cnt <= 0) break;
        string title = v[i].second;
        int score = v[i].first;

        if(tmp.find(title) == tmp.end()) {
            tmp.insert(title);
            ans_max += score;
            cnt--;
        }
    }

    cout << ans_min << " " << ans_max;
}

void input() {
    cin >> N >> M >> K;

    for(int i = 0; i < N; i++) {
        string s;
        int a;

        cin >> s >> a;

        m[s] = a;
        v.push_back({a, s});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
