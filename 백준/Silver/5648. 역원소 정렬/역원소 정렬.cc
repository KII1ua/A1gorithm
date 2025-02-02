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
vector<ll> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;

        string tmp = "";
        for(int j = s.size() - 1; j >= 0; j--) {
            tmp += s[j];
        }

        ll num = stol(tmp);
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++) {
        cout << v[i] << endl;
    }
}
