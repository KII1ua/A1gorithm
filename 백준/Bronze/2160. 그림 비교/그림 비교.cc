#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    char map[5][7];
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
char graph[251][7];
int arr[2];
vector<coordinate> v;
pii result;
int rescount = MAX;

int check(int x, int y) {
    int count = 0;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 7; j++) {
            if(v[x].map[i][j] != v[y].map[i][j]) {
                count++;
            }
        }
    }
    return count;
}

void bt(int idx, int cnt) {
    if(cnt == 2) {
        int tmpcnt = check(arr[0], arr[1]);

        if(rescount > tmpcnt) {
            result.first = arr[0];
            result.second = arr[1];
            rescount = tmpcnt;
        }
        return;
    }

    for(int i = idx; i < N; i++) {
        arr[cnt] = i;
        bt(i+1, cnt+1);
    }
}

void solve() {
    bt(0, 0);

    cout << result.first + 1 << " " << result.second + 1;
}

void input() {
    cin >> N;

    for(int i = 0; i < N * 5; i++) {
        for(int j = 0; j < 7; j++) {
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        coordinate num;
        for(int r = 0; r < 5; r++) {
            for(int c = 0; c < 7; c++) {
                num.map[r][c] = graph[i * 5 + r][c];
            }
        }
        v.push_back(num);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}