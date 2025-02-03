// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
priority_queue<int, vector<int>, greater<int>> minq;
priority_queue<int> maxq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if(maxq.size() > minq.size()) minq.push(a); // 최대힙의 크기는 항상 최소힙의 크기보다 같거나 1만큼 더 크다.
        else maxq.push(a);

        if(!maxq.empty() && !minq.empty()) {        // 최소 힙의 모든 원소는 최대힙의 모든 원소보다 항상 같거나 커야한다.
            if(maxq.top() > minq.top()) {
                int a = maxq.top();
                int b = minq.top();

                maxq.pop();
                minq.pop();

                maxq.push(b);
                minq.push(a);
            }
        }
        cout << maxq.top() << endl;
    }
}
