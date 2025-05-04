#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
deque<int> dq;

/*
 *  1 X : 정수 X를 덱 앞에 넣는다.
 *  2 X : 정수 X를 덱 뒤에 넣는다.
 *  3 : 덱에 정수가 있는경우 맨 앞의 정수를 출력(없을경우 -1출력)
 *  4 : 덱에 정수가 있는경우 맨 뒤의 정수를 빼고 출 (없을경우 -1 출력)
 *  5 : 덱에 들어있는 정수의 개수 출력
 *  6 : 덱이 비어있으면 1, 아니면 0 출력
 *  7 : 덱에 정수가 있다면 맨 앞의 정수를 출력(없을 경우 -1 출력)
 *  8 : 덱에 정수가 있는경우 맨 뒤의 정수를 출력(없을경우 -1 출력)
 */

void solve() {

}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a;
        if(a == 1) {
            cin >> b;
            dq.push_front(b);
        }
        else if(a == 2) {
            cin >> b;
            dq.push_back(b);
        }
        else if(a == 3) {
            if(dq.empty()) cout << -1 << endl;
            else {
                int tmp = dq.front();
                dq.pop_front();
                cout << tmp << endl;
            }
        }
        else if(a == 4) {
            if(dq.empty()) cout << -1 << endl;
            else {
                int tmp = dq.back();
                dq.pop_back();
                cout << tmp << endl;
            }
        }
        else if(a == 5) {
            cout << dq.size() << endl;
        }
        else if(a == 6) {
            if(dq.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(a == 7) {
            if(dq.empty()) cout << -1 << endl;
            else {
                cout << dq.front() << endl;
            }
        }
        else {
            if(dq.empty()) cout << -1 << endl;
            else {
                cout << dq.back() << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}