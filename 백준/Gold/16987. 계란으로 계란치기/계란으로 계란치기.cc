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
int N, answer;
vector<pii> v;

void func(int x) {     // 계란 위치
    if(x == N) {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(v[i].first <= 0) cnt++;
        }

        answer = max(answer, cnt);
        return;
    }

    for(int i = 0; i < N; i++) {
        if(v[x].first <= 0) func(x+1);
        else if(x == i || v[i].first <= 0) continue;
        else {
            v[i].first -= v[x].second;
            v[x].first -= v[i].second;
            func(x+1);
            v[i].first += v[x].second;
            v[x].first += v[i].second;
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(v[i].first <= 0) cnt++;
    }

    answer = max(answer, cnt);
}

void solve() {
    func(0);

    cout << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}