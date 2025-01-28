// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int N, M;

    cin >> N >> M;

    cout << N * M;

}
