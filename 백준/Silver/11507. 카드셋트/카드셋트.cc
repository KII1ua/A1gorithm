#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n";

bool compare(string a, string b) {
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    map<string, int> m;
    vector<string> p;
    vector<string> k;
    vector<string> h;
    vector<string> t;

    string S;
    string tmp;

    cin >> S;

    for(int i = 0; i < S.size(); i += 3) {
        tmp = "";
        for(int j = i; j < i+3; j++) {
            tmp += S[j];
        }
        if(m.find(tmp) != m.end()) {        // 존재할 경우
            cout << "GRESKA";
            return 0;
        } else {                                // 존재하지 않을 경우
            m[tmp] = 1;
        }
        if(tmp[0] == 'P') {
            p.push_back(tmp);
        } else if(tmp[0] == 'K') {
            k.push_back(tmp);
        } else if(tmp[0] == 'H') {
            h.push_back(tmp);
        } else {
            t.push_back(tmp);
        }
    }
    cout << 13 - p.size() << " " << 13 - k.size() << " " << 13 - h.size() << " " << 13 - t.size();
}