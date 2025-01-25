// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
unordered_map<string, int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;

    cin >> s;

    for(int i = 1; i <= s.size(); i++) {
        for(int j = 0; j <= s.size() - i; j++) {
            string tmp = s.substr(j, i);
            if(m.find(tmp) == m.end()) m[tmp] = 1;
            else m[tmp]++;
        }
    }

    cout << m.size();
}
