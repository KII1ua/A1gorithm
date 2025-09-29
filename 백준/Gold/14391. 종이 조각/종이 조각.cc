#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
    int r;
};

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, M;
int graph[5][5];

void Print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    int answer = 0;

    for(int i = 0; i < (1 << N * M); i++) {
        int sum = 0;
        // 가로 찾기
        for(int k = 0; k < N; k++) {
            int val = 0;
            for(int l = 0; l < M; l++) {
                if(i & (1 << (M * k + l))) {
                    sum += val;
                    val = 0;
                }
                else val = val * 10 + graph[k][l];
            }
            sum += val;
        }

        // 세로 찾기
        for(int k = 0; k < M; k++) {
            int val = 0;
            for(int l = 0; l < N; l++) {
                if(i & (1 << (M * l + k))) {
                    val = val * 10 + graph[l][k];
                }
                else {
                    sum += val;
                    val = 0;
                }
            }
            sum += val;
        }
        answer = max(answer, sum);
    }

    cout << answer;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < M; j++) {
            graph[i][j] = s[j] - '0';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
