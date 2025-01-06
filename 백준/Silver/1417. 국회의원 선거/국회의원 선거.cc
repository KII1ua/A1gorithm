// baekjoon 4889
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025
int arr[50];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, dasom, a;
    int cnt = 0;
    priority_queue<int> pq;

    cin >> N;
    cin >> dasom;

    if(N == 1) {
        cout << 0;
        return 0;
    }

    for(int i = 0; i < N-1; i++) {
        cin >> a;
        pq.push(a);
    }

    while(!pq.empty()) {
        int tp = pq.top();
        pq.pop();

        if(dasom > tp) {
            break;
        }
        else {
            tp--;
            dasom++;
            cnt++;
            pq.push(tp);
        }
    }
    cout << cnt;
}