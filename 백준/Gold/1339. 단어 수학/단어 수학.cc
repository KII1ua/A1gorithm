#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 11;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
string arr[MAX];
map<char, int> m;
vector<pair<int, char>> v;

void Print() {
    for(auto &iter : v) {
        cout << iter.first << " " << iter.second << endl;
    }
}

bool compare(pair<int, char> a, pair<int, char> b) {
    return a.first > b.first;
}

void solve() {
    for(int i = 0; i < N; i++) {
        int tmp = 1;
        for(int j = arr[i].size() - 1; j >= 0; j--) {
            m[arr[i][j]] += tmp;
            tmp *= 10;
        }
    }

    for(auto &iter : m) {
        v.push_back({iter.second, iter.first});
    }

    sort(v.begin(), v.end(), compare);

    int cnt = 9;
    int answer = 0;

    for(int i = 0; i < v.size(); i++) {
        int value = v[i].first;

        answer += value * cnt--;
    }

    cout << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}