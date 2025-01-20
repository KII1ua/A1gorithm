// baekjoon 1504
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int arr[5][5];
bool visited[5][5];
map<int, pair<int, int>> m;

int bingo() {
    int result = 0;

    for(int i = 0; i < 5; i++) {
        bool isvisited = false;
        for(int j = 0; j < 5; j++) {
            if(!visited[i][j]) {
                isvisited = true;
                break;
            }
        }
        if(!isvisited) result++;
    }

    for(int i = 0; i < 5; i++) {
        bool isvisited = false;
        for(int j = 0; j < 5; j++) {
            if(!visited[j][i]) {
                isvisited = true;
                break;
            }
        }
        if(!isvisited) result++;
    }

    bool isvisited = false;
    for(int i = 0; i < 5; i++) {
        if(!visited[i][i]) {
            isvisited = true;
            break;
        }
    }
    if(!isvisited) result++;

    int k = 4;
    isvisited = false;
    for(int i = 0; i < 5; i++) {
        if(!visited[i][k-i]) {
            isvisited = true;
            break;
        }
    }
    if(!isvisited) result++;

    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int N, a;
    int cnt = 0;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> arr[i][j];
            m[arr[i][j]] = {i, j};
        }
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> a;
            cnt++;

            if(m.count(a)) {
                auto [x, y] = m[a];
                visited[x][y] = true;
            }

            if(bingo() >= 3) {
                cout << cnt;
                return 0;
            }
        }
    }
}