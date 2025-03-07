// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int T, N, M;

void input() {
    cin >> T;

    while(T--) {
        unordered_map<int, int> um;
        cin >> N;

        for(int i = 0; i < N; i++) {
            int a;
            cin >> a;
            if(um.find(a) != um.end()) {
                um[a]++;
            }
            else um[a] = 1;
        }

        cin >> M;

        for(int i = 0; i < M; i++) {
            int a;
            cin >> a;
            if(um.find(a) != um.end()) {
                cout << 1 << endl;
            }
            else cout << 0 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
