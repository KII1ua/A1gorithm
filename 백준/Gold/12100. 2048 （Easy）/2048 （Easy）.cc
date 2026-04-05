#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int left, right;
};

const int INF = 1e9;
const int MAX = 100001;
const int D = 2000000;
const int MOD = 10007;
//int dx[] = {0, 0, 1, -1};
//int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int N, ans;
int graph[21][21];
bool merged[21][21];

void copy(int board[][21], int tmpgraph[][21]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            tmpgraph[i][j] = board[i][j];
        }
    }
}

void left(int board[][21]) {
    memset(merged, 0, sizeof(merged));
    for(int i = 0; i < N; i++) {
        vector<int> v;
        for (int j = 0; j < N; j++) {
            if(board[i][j] != 0) {
                v.push_back(board[i][j]);
                board[i][j] = 0;
            }
        }

        int idx = 0;
        for(int k = 0; k < v.size(); k++) {
            if(idx > 0 && board[i][idx-1] == v[k] && !merged[i][idx-1]) {
                board[i][idx-1] *= 2;
                merged[i][idx-1] = true;
            }
            else board[i][idx++] = v[k];
        }
    }
}

void right(int board[][21]) {
    memset(merged, 0, sizeof(merged));
    for(int i = 0; i < N; i++) {
        vector<int> v;
        for(int j = N-1; j >= 0; j--) {
            if(board[i][j] != 0) {
                v.push_back(board[i][j]);
                board[i][j] = 0;
            }
        }

        int idx = N-1;
        for(int k = 0; k < v.size(); k++) {
            if(idx < N-1 && board[i][idx+1] == v[k] && !merged[i][idx+1]) {
                board[i][idx+1] *= 2;
                merged[i][idx+1] = true;
            }
            else {
                board[i][idx--] = v[k];
            }
        }
    }
}

void up(int board[][21]) {
    memset(merged, 0, sizeof(merged));
    for(int j = 0; j < N; j++) {
        vector<int> v;
        for(int i = 0; i < N; i++) {
            if(board[i][j] != 0) {
                v.push_back(board[i][j]);
                board[i][j] = 0;
            }
        }

        int idx = 0;
        for(int k = 0; k < v.size(); k++) {
            if(idx > 0 && board[idx-1][j] == v[k] && !merged[idx-1][j]) {
                board[idx-1][j] *= 2;
                merged[idx-1][j] = true;
            }
            else {
                board[idx++][j] = v[k];
            }
        }
    }
}

void down(int board[][21]) {
    memset(merged, 0, sizeof(merged));
    for(int j = 0; j < N; j++) {
        vector<int> v;
        for(int i = N-1; i >= 0; i--) {
            if(board[i][j] != 0) {
                v.push_back(board[i][j]);
                board[i][j] = 0;
            }
        }

        int idx = N-1;
        for(int k = 0; k < v.size(); k++) {
            if(idx < N-1 && board[idx+1][j] == v[k] && !merged[idx+1][j]) {
                board[idx+1][j] *= 2;
                merged[idx+1][j] = true;
            }
            else {
                board[idx--][j] = v[k];
            }
        }
    }
}

int findmaxValue(int board[][21]) {
    int answer = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            answer = max(answer, board[i][j]);
        }
    }

    return answer;
}

void bt(int cnt ,int board[][21]) {
    if(cnt == 5) {
        ans = max(ans, findmaxValue(board));
        return;
    }

    for(int i = 0; i < 4; i++) {
        int tmpgraph[21][21];
        copy(board, tmpgraph);

        if(i == 0) left(tmpgraph);
        else if(i == 1) right(tmpgraph);
        else if(i == 2) up(tmpgraph);
        else down(tmpgraph);

        bt(cnt+1, tmpgraph);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    bt(0, graph);

    cout << ans;
}