// baekjoon 4889
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    string s;
    int cnt = 0;
    vector<char> c;

    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> s;

        if(!next_permutation(s.begin(), s.end())) {
            prev_permutation(s.begin(), s.end());
        }

        for(auto it : s) cout << it;
        cout << endl;
    }
}