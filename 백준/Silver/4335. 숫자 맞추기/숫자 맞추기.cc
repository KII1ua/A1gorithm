// baekjoon 1504
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;
    int a;

    while(true) {
        vector<int> high;
        vector<int> low;
        int tmp;
        bool visited = true;
        while(true) {
            cin >> a;

            if(a == 0) return 0;

            cin.ignore();
            getline(cin, s);

            if(s[4] == 'h') high.push_back(a);
            else if(s[4] == 'l') low.push_back(a);
            else {
                tmp = a;
                break;
            }
        }
        for(int i = 0; i < high.size(); i++) {
            if(tmp >= high[i]) {
                visited = false;
                break;
            }
        }

        for(int j = 0; j < low.size(); j++) {
            if(tmp <= low[j]) {
                visited = false;
                break;
            }
        }

        if(!visited) {
            cout << "Stan is dishonest" << endl;
        } else {
            cout << "Stan may be honest" << endl;
        }
    }
}
