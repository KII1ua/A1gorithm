#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N;
string s;
int lowalpha[26];
int tc = 1;

void solve() {
    int result = MAX;

    for(int i = 0; i < s.size(); i++) {
        char stand = s[i];

        if(stand >= 65 && stand <= 90) {
            int idx = stand - 'A';
            lowalpha[idx]++;
        }
        else if(stand >= 97 && stand <= 122) {
            int idx = stand - 'a';
            lowalpha[idx]++;
        }
    }

    for(int i = 0; i < 26; i++) {
        result = min(lowalpha[i], result);
    }

    if(result == 0) {
        cout << "Case " << tc << ": " << "Not a pangram" << endl;
    }
    else if(result == 1) cout << "Case " << tc << ": " << "Pangram!" << endl;
    else if(result == 2) cout << "Case " << tc << ": " << "Double pangram!!" << endl;
    else cout << "Case " << tc << ": " << "Triple pangram!!!" << endl;

    memset(lowalpha, 0, sizeof(lowalpha));
    tc++;
}

void input() {
    cin >> N;

    cin.ignore();

    for(int i = 0; i < N; i++) {
        getline(cin, s);
        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}