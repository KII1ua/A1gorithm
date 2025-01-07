// baekjoon 4889
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
char arr[21][21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int R, C;
    string s;
    vector<string> v;

    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        cin >> s;
        for(int j = 0; j < C; j++) {
            arr[i][j] = s[j];
        }
    }

    for(int i = 0; i < R; i++) {
        string tmp = "";
        for(int j = 0; j < C; j++) {
            if(arr[i][j] != '#') {
                tmp += arr[i][j];
            }
            else {
                if(tmp.length() >= 2) {
                    v.push_back(tmp);
                }
                tmp = "";
            }
        }
        if(tmp.length() >= 2) {
            v.push_back(tmp);
        }
    }

    for(int i = 0; i < C; i++) {
        string tmp = "";
        for(int j = 0; j < R; j++) {
            if(arr[j][i] != '#') {
                tmp += arr[j][i];
            }
            else {
                if(tmp.length() >= 2) {
                    v.push_back(tmp);
                }
                tmp = "";
            }
        }
        if(tmp.length() >= 2) {
            v.push_back(tmp);
        }
    }

    sort(v.begin(), v.end());

    cout << v[0];
}