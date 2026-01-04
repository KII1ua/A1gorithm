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
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string s;

vector<int> makeTable(const string &str) {
    vector<int> table(str.size(), 0);
    int j = 0;

    for(int i = 1; i < str.size(); i++) {
        while(j > 0 && str[i] != str[j]) j = table[j-1];

        if(str[i] == str[j]) table[i] = ++j;
    }

    return table;
}

void solve() {
    int answer = 0;

    for(int i = 0; i < s.size(); i++) {
        string st = s.substr(i);

        vector<int> v = makeTable(st);

        for(auto it : v) {
            answer = max(it, answer);
        }
    }

    cout << answer;
}

void input() {
    cin >> s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}