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
bool arr[9999999];
string s;
bool visited[8];
string result[8];
set<int> st;

int convert(string res) {
    if(res[0] == '0') {
        return 0;
    }
    return stoi(res);
}

void dfs(int x, int cnt) {
    if(x == cnt) {
        string tmp = "";
        for(int i = 0; i < cnt; i++) {
            tmp += result[i];
        }
        int sol = convert(tmp);

        if(!arr[sol]) {
            st.insert(sol);
        }
        return;
    }

    for(int i = 0; i < s.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            result[x] = s[i];
            dfs(x+1, cnt);
            visited[i] = false;
        }
    }
}

void isprime() {
    arr[0] = true;
    arr[1] = true;

    for(int i = 2; i < sqrt(9999999); i++) {
        if(!arr[i]) {
            for(int j = i + i; j <= 9999999; j += i) {
                arr[j] = true;
            }
        }
    }
}

void solve() {
    isprime();

    cin >> N;

    while(N--) {
        cin >> s;

        for(int i = 1; i <= s.size(); i++) {
            dfs(0, i);
        }

        cout << st.size() << endl;
        st.clear();
        memset(result, 0, sizeof(result));
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();
}