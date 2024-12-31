// baekjoon 28706
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};

bool compare(string a, string b) {
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T, N;

    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> N;
        set<int> s;
        s.insert(1);
        for (int j = 0; j < N; j++) {
            set<int> tmp;
            int v1, v2;
            string op1, op2;

            cin >> op1 >> v1 >> op2 >> v2;
            for (auto value: s) {
                if (op1 == "+") {
                    tmp.insert((v1 + value) % 7);
                } else if (op1 == "*") {
                    tmp.insert((v1 * value) % 7);
                }
                if (op2 == "+") {
                    tmp.insert((v2 + value) % 7);
                } else if (op2 == "*") {
                    tmp.insert((v2 * value) % 7);
                }
            }
            s = tmp;
        }
        if(s.find(0) == s.end()) cout << "UNLUCKY" << endl;     // 만약 0이 없을 경우 find는 end를 리턴한다.
        else cout << "LUCKY" << endl;
    }
}