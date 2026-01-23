#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 201;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<int> v;
bool visited[MAX][MAX][MAX];
set<int> st;

void bfs() {
    queue<tuple<int, int, int>> q;
    q.push({0, 0, v[2]});
    visited[0][0][v[2]] = true;
    st.insert(v[2]);
    int arr[3] = {0};
    int nextarr[3] = {0};

    while(!q.empty()) {
        arr[0] = get<0>(q.front());
        arr[1] = get<1>(q.front());
        arr[2] = get<2>(q.front());
        q.pop();

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                copy(arr, arr+3, nextarr);
                if(i == j) continue;

                if(nextarr[i] <= 0) continue;

                if(nextarr[i] + nextarr[j] > v[j]) {      // 용량을 넘을 때
                    int diff = v[j] - nextarr[j];
                    nextarr[i] -= diff;
                    nextarr[j] += diff;
                }
                else {      // 용량을 못채울때
                    nextarr[j] += nextarr[i];
                    nextarr[i] = 0;
                }

                if(!visited[nextarr[0]][nextarr[1]][nextarr[2]]) {
                    q.push({nextarr[0], nextarr[1], nextarr[2]});
                    visited[nextarr[0]][nextarr[1]][nextarr[2]] = true;

                    if(nextarr[0] == 0) {
                        st.insert(nextarr[2]);
                    }
                }
            }
        }
    }
}

void solve() {
    bfs();

    for(auto it : st) {
        cout << it << " ";
    }
}

void input() {
    for(int i = 0; i < 3; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}