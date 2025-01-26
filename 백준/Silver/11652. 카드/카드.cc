// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
map<ll, int> m;
pair<ll, int> result;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        if(m.find(a) != m.end()) {
            m[a]++;
        } else m[a] = 1;
    }

    for(auto it : m) {
        if(it.second > result.second) {
            result.second = it.second;
            result.first = it.first;
        }
    }

    cout << result.first;
}
