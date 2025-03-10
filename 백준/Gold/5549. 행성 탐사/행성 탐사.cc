// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N, M, K;
char graph[1001][1001];
int graphj[1001][1001];
int graphi[1001][1001];
int grapho[1001][1001];

void input() {
    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++) {
        char a;

        for(int j = 1; j <= M; j++) {
            cin >> a;
            graph[i][j] = a;
            if(a == 'J') {
                graphj[i][j]++;
            }
            else if(a == 'I') {
                graphi[i][j]++;
            }
            else if(a == 'O') {
                grapho[i][j]++;
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            graphj[i][j] = graphj[i-1][j] + graphj[i][j-1] + graphj[i][j] - graphj[i-1][j-1];
            graphi[i][j] = graphi[i-1][j] + graphi[i][j-1] + graphi[i][j] - graphi[i-1][j-1];
            grapho[i][j] = grapho[i-1][j] + grapho[i][j-1] + grapho[i][j] - grapho[i-1][j-1];
        }
    }

    for(int i = 0; i < K; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << graphj[c][d] - graphj[a-1][d] - graphj[c][b-1] + graphj[a-1][b-1] << " ";
        cout << grapho[c][d] - grapho[a-1][d] - grapho[c][b-1] + grapho[a-1][b-1] << " ";
        cout << graphi[c][d] - graphi[a-1][d] - graphi[c][b-1] + graphi[a-1][b-1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
