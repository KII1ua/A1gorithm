#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N;
queue<int> q;
int len, result, last;

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a;

        if(a == 1) {
            cin >> b;
            q.push(b);
            len++;
            if(len > result) {      // 길이가 커질경우
                result = len;
                last = b;
            }
            else if(len == result) {
                if(last < b) continue;
                else last = b;
            }
        }
        else {
            q.pop();
            len--;
        }
    }

    cout << result << " " << last;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
