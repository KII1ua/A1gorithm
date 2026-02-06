#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 2e9;
const int MAX = 1001;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int T, N, M;
bool visited[MAX];

bool compare(pii a, pii b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

void Print(vector<pii> &v) {
    for(auto &iter : v) {
        cout << iter.first << " " << iter.second << endl;
    }
}

void solve(vector<pii> &v) {
    sort(v.begin(), v.end(), compare);

    int answer = 0;

    for(int i = 0; i < M; i++) {
        int lo = v[i].first;
        int hi = v[i].second;

        if(!visited[lo]) {
            visited[lo] = true;
            answer++;
        }
        else {
            for(int i = lo + 1; i <= hi; i++) {
                if(!visited[i]) {
                    answer++;
                    visited[i] = true;
                    break;
                }
            }
        }
    }

    cout << answer << endl;
}

void input() {
    cin >> T;

    while(T--) {
        cin >> N >> M;

        vector<pii> v;
        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }

        solve(v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}