#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    string s;
    vector<int> v;
};

int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
int N, M;
int parkCharge[101];
int carweight[2001];
int arr[101];

void solve() {
    priority_queue<int, vector<int>, greater<int>> pq;
    queue<int> q;

    for(int i = 1; i <= N; i++) {
        pq.push(i);
    }

    ll cost = 0;

    for(int i = 0; i < 2 * M; i++) {
        int a;
        cin >> a;

        if(a > 0) {     // 주차
            if(!pq.empty()) {       // 주차할 수 있는 경우
                int parkNum = pq.top();
                pq.pop();

                cost += parkCharge[parkNum] * carweight[a];
                arr[parkNum] = a;       // idx : 주차번호, value : 차 종류
            }
            else {      // 대기 해야함
                q.push(a);
            }
        }
        else {
            int car = a * -1;

            for(int i = 1; i <= N; i++) {       // i : 주차장 번호
                if(arr[i] == car) {     // 주차된거 나와야됨
                    arr[i] = 0;
                    pq.push(i);

                    if(!q.empty() && !pq.empty()) {            // 차 대기열이 있는 경우
                        int carNum = q.front();     // 차 번호
                        q.pop();
                        int parkNum = pq.top();     // 주차장 번호
                        pq.pop();
                        arr[parkNum] = carNum;

                        cost += parkCharge[parkNum] * carweight[carNum];
                    }
                    break;
                }
            }
        }
    }

    cout << cost;
}

void input() {
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        cin >> parkCharge[i];
    }

    for(int i = 1; i <= M; i++) {
        cin >> carweight[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}