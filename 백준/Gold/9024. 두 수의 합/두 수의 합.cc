#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
int T, N, K;
vector<int> v;

void solve() {
    int minval = MAX;
    sort(v.begin(), v.end());

    int left = 0;
    int right = N-1;
    int cnt = 0;

    while(left < right) {
        int val = v[left] + v[right];

        if(val == K) left++, right--;
        else if(val > K) right--;
        else if(val < K) left++;

        int vals = abs(K - val);

        if(vals == minval) cnt++;

        if(minval > vals) {
            cnt = 1;
            minval = vals;
        }
    }

    cout << cnt << endl;
}

void input() {
    cin >> T;

    while(T--) {
        cin >> N >> K;

        for(int i = 0; i < N; i++) {
            int a;
            cin >> a;
            v.push_back(a);
        }

        solve();

        v.clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}