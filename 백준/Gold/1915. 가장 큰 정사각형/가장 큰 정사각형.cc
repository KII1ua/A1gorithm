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
int graph[1001][1001];
int maxlen;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    cin.ignore();

    for(int i = 1; i <= N; i++) {
        string s;
        getline(cin, s);

        for(int j = 1; j <= M; j++) {
            graph[i][j] = s[j-1] - '0';
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(graph[i][j] != 0) {
                graph[i][j] = min(graph[i][j-1], min(graph[i-1][j-1], graph[i-1][j])) + 1;
                maxlen = max(maxlen, graph[i][j]);
            }
        }
    }

    cout << maxlen * maxlen;
}
