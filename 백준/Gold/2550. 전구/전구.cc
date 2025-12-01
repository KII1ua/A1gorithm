#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
vector<int> v;
map<int, int> m;
map<int, int> tb;
int Index[10001];
pii arr[10001];

void Print() {
    for(int i = 0; i < N; i++) {
        cout << Index[i] << " ";
    }
}

void solve() {
    for(int i = 0; i < N; i++) {
        int value = arr[i].first;
        int locate = arr[i].second;

        if(v.empty() || v[v.size()-1] < locate) {
            v.push_back(locate);
            Index[i] = v.size()-1;
        }
        else {
            int idx = lower_bound(v.begin(), v.end(), locate) - v.begin();

            v[idx] = locate;
            Index[i] = idx;
        }
    }

    cout << v.size() << endl;

    vector<int> answer;

    int idx = v.size()-1;

    for(int i = N-1; i >= 0; i--) {
        if(Index[i] == idx) {
            answer.push_back(arr[i].first);
            idx--;
        }
    }

    sort(answer.begin(), answer.end());

    for(auto it : answer) {
        cout << it << " ";
    }
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        arr[i].first = a;
        m[a] = i;
    }

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        int idx = m[a];
        arr[idx].second = i;
        tb[i] = a;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}