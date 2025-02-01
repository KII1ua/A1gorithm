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

void bt(int x, int cnt) {
    if(cnt == M) {
        for(int i = 0; i < M; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = x; i < N; i++) {
        result[cnt] = v[i];
        bt(i, cnt+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    bt(0, 0);
}
