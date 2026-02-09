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
string s1, s2;

void solve() {
    int idx1 = -1;
    int idx2 = s2.size();

    for(int i = 0; i < min(s2.size(), s1.size()); i++) {
        if(s1[i] != s2[i]) {
            break;
        }
        idx1 = i;
    }

    int i = s1.size()-1;
    int j = s2.size()-1;

    for(; i >= 0 && j >= 0 && i > idx1 && j > idx1; i--, j--) {
        if(s1[i] != s2[j]) {
            break;
        }
        idx2--;
    }

    cout << idx2 - idx1 - 1;
}

void input() {
    cin >> s1 >> s2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}