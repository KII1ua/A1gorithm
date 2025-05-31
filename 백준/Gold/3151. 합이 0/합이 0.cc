#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e11

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int N;
ll result;
vector<int> v;

void solve() {
    sort(v.begin(), v.end());

    for(int i = 0; i < N-1; i++) {
        for(int j = i + 1; j < N; j++) {
            int c = v[i] + v[j];

            int idx1 = lower_bound(v.begin() + j + 1, v.end(), -c) - v.begin();
            int idx2 = upper_bound(v.begin() + j + 1, v.end(), -c) - v.begin();
            result += idx2 - idx1;
        }
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