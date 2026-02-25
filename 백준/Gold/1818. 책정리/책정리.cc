#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 40;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
vector<int> v, answer;

int Lower_bound(int value) {
    int lo = -1;
    int hi = answer.size()-1;

    while(lo + 1< hi) {
        int mid = (lo + hi) / 2;

        if(answer[mid] <= value) {
            lo = mid;
        }
        else hi = mid;
    }

    return hi;
}

void solve() {
    for(int i = 0; i < N; i++) {
        int value = v[i];

        if(answer.empty() || answer[answer.size()-1] < value) answer.push_back(value);
        else {
            int idx = Lower_bound(value);

            answer[idx] = value;
        }
    }

    cout << N - answer.size();
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