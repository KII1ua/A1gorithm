#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 200001;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
vector<pii> v;

bool compare(pii a, pii b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void Print() {
    for(auto &it : v) {
        cout << it.first << " " << it.second << endl;
    }
}

void solve() {
    sort(v.begin(), v.end());

    int cnt = 0;
    int start = 0;
    int end = 0;
    int answer = 0;

    bool flag = false;
    for(int i = 0; i < v.size(); i++) {
        cnt += v[i].second;

        if(i + 1 < v.size() && v[i].first == v[i+1].first) {
            continue;
        }

        if(cnt > answer) {
            answer = cnt;
            start = v[i].first;
            flag = true;
        }
        else if(cnt < answer && flag) {
            end = v[i].first;
            flag = false;
        }
    }

    cout << answer << endl << start << " " << end;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, -1});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}