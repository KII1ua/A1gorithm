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
int N, S;
vector<int> v;

void solve() {
    vector<int> left, right;
    int half = (N % 2 == 0)? N / 2 : N / 2 + 1;

    for(int i = 0; i < (int)pow(2, half); i++) {
        int value = 0;
        for(int j = 0; j < half; j++) {
            if(i & (1 << j)) {
                value += v[j];
            }
        }
        left.push_back(value);
    }

    for(int i = 0; i < (1 << (N - half)); i++) {
        int value = 0;
        for(int j = 0; j < N - half; j++) {
            if(i & (1 << j)) {
                value += v[half+j];
            }
        }
        right.push_back(value);
    }

    sort(right.begin(), right.end());

    ll answer = 0;
    for(int i = 0; i < left.size(); i++) {
        int value = S - left[i];

        int lo = lower_bound(right.begin(), right.end(), value) - right.begin();
        int ri = upper_bound(right.begin(), right.end(), value) - right.begin();

        answer += ri - lo;
    }

    if(S == 0) {
        answer--;
    }

    cout << answer;

}

void input() {
    cin >> N >> S;

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