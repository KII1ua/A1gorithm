#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
    int r;
};

int dx[] = {0 ,0, -1, 0, 1, 1, -1, -1, 1};
int dy[] = {0, -1, 0, 1, 0, -1, 1, -1, 1};
string s;

bool palindrome(string a, int left) {
    int right = a.size() - 1;

    while(left < right) {
        if(a[left] != a[right]) return false;
        left++, right--;
    }

    return true;
}

void solve() {
    int sz = s.size();

    for(int i = 0; i < sz; i++) {
        if(palindrome(s, i)) {
            cout << sz + i;
            return;
        }
    }

    cout << sz * 2 -1;
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
