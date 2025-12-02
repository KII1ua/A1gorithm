#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string s;
vector<pii> v;

void Print() {
    for(auto it : v) {
        cout << it.first << " " << it.second << endl;
    }
}

void solve() {
    set<string> ans;
    vector<string> answer;
    stack<int> st;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(i);
        }
        else if(s[i] == ')') {
            int idx = st.top();
            st.pop();
            v.push_back({idx, i});
        }
    }

    int cnt = v.size();
    int n = (1 << cnt) - 1;

    for(int i = 0; i < n; i++) {
        bool flag = false;
        string tmp = "";
        set<int> st;
        for(int j = 0; j < cnt; j++) {
            if(i & (1 << j)) {
                st.insert(v[j].first);
                st.insert(v[j].second);
                flag = true;
            }
        }

        if(!flag)  {
            for(int j = 0; j < s.size(); j++) {
                if(s[j] == '(' || s[j] == ')') continue;
                tmp += s[j];
            }
        }
        else {
            for(int j = 0; j < s.size(); j++) {
                if(st.find(j) != st.end()) {
                    continue;
                }
                tmp += s[j];
            }
        }
        ans.insert(tmp);
    }

    for(auto it : ans) {
        answer.push_back(it);
    }

    sort(answer.begin(), answer.end());

    for(auto it : answer) {
        cout << it << endl;
    }
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