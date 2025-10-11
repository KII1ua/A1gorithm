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
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};
int N;
deque<char> dq;
deque<int> idx;

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;

        cin >> a;

        if(a == 1) {
            char b;
            cin >> b;
            dq.push_back(b);
            idx.push_back(1);
        }
        else if(a == 2) {
            char b;
            cin >> b;
            dq.push_front(b);
            idx.push_back(2);
        }
        else {
            if(!idx.empty()) {
                int idx1 = idx.back();
                idx.pop_back();

                if(idx1 == 1) {
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }
            }
        }
    }

    if(dq.empty()) {
        cout << 0;
        return;
    }

    while(!dq.empty()) {
        char a = dq.front();
        dq.pop_front();

        cout << (char)a;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
