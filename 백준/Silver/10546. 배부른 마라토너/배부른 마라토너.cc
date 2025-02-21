// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N;
unordered_map<string, int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if(m.find(s) != m.end()) {
            m[s]++;
        }
        else m[s] = 1;
    }

    for(int i = 0; i < N-1; i++) {
        string s;
        cin >> s;
        if(m.find(s) != m.end()) {
            m[s]--;
        }
    }
    
    for(auto it : m) {
        if(it.second != 0) {
            cout << it.first;
            return 0;
        }
    }
}
