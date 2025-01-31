// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, M;
vector<int> v;
int result[9];
bool visited[9];

void bt(int x, int idx) {
    if(x == M) {
        for(int i = 0; i < M; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = idx + 1; i < N; i++) {
        result[x] = v[i+1];
        bt(x+1, i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    v.push_back(0);

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    bt(0, -1);
}
