// baekjoon 2206
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, M;
bool visited[8];
int arr[8];

void bt(int x) {
    if(x == M) {
        for(int j = 0; j < M; j++) {
            cout << arr[j] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = 1; i <= N; i++) {
        visited[i] = true;
        arr[x] = i;
        bt(x+1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    bt(0);
}
