// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N, M, V;
int graph[200001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> V;

    for(int i = 0; i < N; i++) {
        cin >> graph[i];
    }

    int len = N - (V - 1);    // 사이클 길이

    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;

        if(a < N) {
            cout << graph[a] << endl;
        }
        else {
            a = a - N;
            a = a % len;
            cout << graph[a + V - 1] << endl;
        }
    }
}
