// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int K;
int arr[7];
int graph[14];
bool visited[7];

void bt(int start, int depth) {
    if(depth == 6) {
        for(int i = 0; i < 6; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = start; i < K; i++) {
        arr[depth] = graph[i];
        bt(i+1, depth+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while(true) {
        cin >> K;
        if(K == 0) return 0;

        for(int i = 0; i < K; i++) {
            cin >> graph[i];
        }

        bt(0, 0);
        cout << endl;
    }
}
