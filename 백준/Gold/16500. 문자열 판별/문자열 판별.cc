// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
vector<string> v;
bool dp[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;
    int N;

    cin >> s >> N;

    for(int i = 0; i < N; i++) {
        string a;
        cin >> a;
        v.push_back(a);
    }

    for(int i = 0; i < s.length(); i++) {
        if(i == 0 || dp[i] != false) {
            for(int j = 0; j < N; j++) {
                string stand = v[j];
                bool flag = false;

                for(int k = 0; k < stand.length(); k++) {
                    if(s[i+k] != stand[k]) {
                        flag = true;
                    }
                }
                if(flag == true) continue;// 하나라도 틀렸다는 경우
                else dp[i + stand.size()] = true;
            }
        }
    }

    if(dp[s.size()] == true)
        cout << 1;
    else
        cout << 0;
}
