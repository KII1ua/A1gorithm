#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, x, y, answer;
int arr[26];
bool visited[13];

void Init() {
    int tmp = y - x - 1;
    arr[x] = arr[y] = tmp;
    visited[tmp] = true;
}

void bt(int idx) {      // idx는 값
    if(idx > n) {
        answer++;
        return;
    }

    if(visited[idx]) bt(idx+1);
    else {
        int ri = 2 * n - idx - 1;
        for(int i = 1; i <= ri; i++) {       // 인덱스
            int temp = i + idx + 1;
            if(!arr[i] && !arr[temp]) {
                arr[i] = arr[temp] = idx;
                bt(idx+1);
                arr[i] = arr[temp] = 0;
            }
        }
    }
}

void solve() {
    Init();
    bt(1);

    cout << answer;
}

void input() {
    cin >> n >> x >> y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}