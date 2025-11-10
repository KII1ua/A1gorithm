#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e11

struct coordinate {
    int x;
    int y;
    int r;
};

struct halloween {
    int cnt;
    int score;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int w, g;
string a, b;
int alpha[52];
int balpha[52];

bool check() {
    for(int i = 0; i < 52; i++) {
        if(alpha[i] != balpha[i]) {
            return false;
        }
    }

    return true;
}

void solve() {
    int answer = 0;

    for(int i = 0; i < w; i++) {
        if(a[i] >= 'A' && a[i] <= 'Z') {
            int idx = a[i] - 'A';
            alpha[idx]++;
        }
        else {
            int idx = a[i] - 'a' + 26;
            alpha[idx]++;
        }
    }

    for(int i = 0; i < w; i++) {
        if(b[i] >= 'A' && b[i] <= 'Z') {
            int idx = b[i] - 'A';
            balpha[idx]++;
        }
        else {
            int idx = b[i] - 'a' + 26;
            balpha[idx]++;
        }
    }

    if(check()) answer++;

    for(int i = w; i < g; i++) {
        if(b[i-w] >= 'A' && b[i-w] <= 'Z') {
            int idx = b[i-w] - 'A';
            balpha[idx]--;
        }
        else {
            int idx = b[i-w] - 'a' + 26;
            balpha[idx]--;
        }

        if(b[i] >= 'A' && b[i] <= 'Z') {
            int idx = b[i] - 'A';
            balpha[idx]++;
        }
        else {
            int idx = b[i] - 'a' + 26;
            balpha[idx]++;
        }

        if(check()) answer++;
    }

    cout << answer;
}

void input() {
    cin >> w >> g >> a >> b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
