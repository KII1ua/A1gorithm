#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 123457;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
int cost[11];

void solve() {
    int min_cost1 = INF;        // 0 포함
    int idx1 = -1;

    int min_cost2 = INF;        // 0이 아닌 수
    int idx2 = -1;

    for(int i = 0; i < N; i++) {
        if(min_cost1 >= cost[i]) {
            min_cost1 = cost[i];
            idx1 = i;
        }

        if(i > 0 && min_cost2 >= cost[i]) {
            min_cost2 = cost[i];
            idx2 = i;
        }
    }

    if(idx2 == -1 || M < min_cost2) {
        cout << 0;
        return;
    }

    string answer = "";

    answer += to_string(idx2);
    M -= min_cost2;

    while(M >= min_cost1) {
        answer += to_string(idx1);
        M -= min_cost1;
    }

    for(int i = 0; i < answer.size(); i++) {
        int value = answer[i] - '0';

        for(int j = N-1; j > value; j--) {
            int totalcost = cost[j] - cost[value];

            if(M >= totalcost) {
                answer[i] = j + '0';
                M -= totalcost;
                break;
            }
        }
    }

    cout << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> cost[i];
    }

    cin >> M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}