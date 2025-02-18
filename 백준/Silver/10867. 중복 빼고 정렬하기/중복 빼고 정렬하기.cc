// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N;
set<int> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }

    for(auto it: s) {
        cout << it << " ";
    }
}
