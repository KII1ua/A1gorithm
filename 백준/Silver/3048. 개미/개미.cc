#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e10

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int N, M, T;
string a, b;
map<char, int> m;

void solve() {
    reverse(a.begin(), a.end());

    for(auto it : a) {
        m[it] = 1;
    }

    string ant = a + b;

    for(int i = 0; i < T; i++) {
        for(int j = 0; j < N+M-1; j++) {
            if(m.count(ant[j]) > 0) {
                if(m.count(ant[j+1]) > 0) {
                    continue;
                }
                else {
                    swap(ant[j], ant[j+1]);
                    j++;
                }
            }
        }
    }

    cout << ant;
}

void input() {
    cin >> N >> M;

    cin >> a >> b >> T;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}