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
int N;
queue<int> q;

void input() {
    cin >> N;

    while(true) {
        int a;
        cin >> a;

        if(a == -1) {
            break;
        }

        if(!a) {
            q.pop();
        }
        else {
            if(q.size() >= N) continue;
            else {
                q.push(a);
            }
        }
    }

    if(q.size() > 0) {
        while(!q.empty()) {
            int a = q.front();
            q.pop();
            cout << a << " ";
        }
    }
    else {
        cout << "emtpty";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
