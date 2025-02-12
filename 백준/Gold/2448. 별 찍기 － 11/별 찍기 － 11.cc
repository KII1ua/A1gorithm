// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
char graph[3072][6149];
int N;

void draw(int x, int y, int n) {
    if(n == 3) {
        graph[x][y] = '*';
        graph[x+1][y-1] = '*';
        graph[x+1][y+1] = '*';
        graph[x+2][y-2] = '*';
        graph[x+2][y-1] = '*';
        graph[x+2][y] = '*';
        graph[x+2][y+1] = '*';
        graph[x+2][y+2] = '*';
    }
    else {
        draw(x, y, n / 2);
        draw(x + n / 2, y - n / 2, n / 2);
        draw(x + n / 2, y + n / 2, n / 2);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 2 * N; j++) {
            graph[i][j] = ' ';
        }
    }

    draw(0, N-1, N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 2 * N; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }
}
