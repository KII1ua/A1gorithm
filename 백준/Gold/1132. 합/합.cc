#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e13

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int64_t alpha[10];
bool zero[10];

void Print() {
    for(int i = 0; i < 10; i++) {
        cout << alpha[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < 10; i++) {
        cout << zero[i] << " ";
    }
    cout << endl;
}

void solve() {
    bool flag = false;
    for(int i = 0; i < 10; i++) {
        if(!alpha[i]) {
            flag = true;
        }
    }

    if(!flag) {     //      이미 알파벳이 다 채워져 0을 
        int64_t tmp = MAX;
        int idx = 0;

        for(int i = 0; i < 10; i++) {
            if(!zero[i] && tmp > alpha[i]) {
                tmp = alpha[i];
                idx = i;
            }
        }
        alpha[idx] = 0;
    }

    sort(alpha, alpha+10, [&](int64_t a, int64_t b) {
        return a > b;
    });

    int64_t answer = 0;
    for(int i = 0, j = 9; i < 10; i++, j--) {
        answer += alpha[i] * j;
    }

    cout << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int64_t cnt = 1;
        string s;

        cin >> s;

        zero[s[0] - 'A'] = 1;

        for(int j = s.size()-1; j >= 0; j--) {
            int idx = s[j] - 'A';
            alpha[idx] += cnt;
            cnt *= 10;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}