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

struct horse {
    int x;
    int y;
    int dir;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};
int dx[] = {1, 0};
int dy[] = {0, 1};
int N;
bool prime[1000001];
vector<int> v;

void Prime() {
    prime[0] = true;
    prime[1] = true;

    for(int i = 2; i <= 1000000; i++) {
        if(!prime[i]) {
            for(int j = i + i; j <= 1000000; j += i) {
                prime[j] = true;
            }
        }
    }
}

void solve() {
    vector<int> answer;

    for(int i = 2; i <= 1000000; i++) {
        if(!prime[i]) {
            v.push_back(i);
        }
    }

    if(N < 8) {
        cout << -1;
        return;
    }

    if(N % 2 == 0) {
        answer.push_back(2);
        answer.push_back(2);
        N -= 4;

        for(int i = 2; i < N; i++) {
            if(!prime[i] && !prime[N-i]) {
                answer.push_back(i);
                answer.push_back(N-i);
                break;
            }
        }
    }
    else {
        answer.push_back(2);
        answer.push_back(3);
        N -= 5;

        for(int i = 2; i < N; i++) {
            if(!prime[i] && !prime[N-i]) {
                answer.push_back(i);
                answer.push_back(N-i);
                break;
            }
        }
    }

    for(auto it : answer) {
        cout << it << " ";
    }
}

void input() {
    cin >> N;

    Prime();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
