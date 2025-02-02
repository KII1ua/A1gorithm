// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
vector<string> v;

int getsum(string a) {
    int len = a.length(), sum = 0;

    for(int i = 0; i < a.length(); i++) {
        if(a[i] - '0' <= 9) {
            sum += a[i] - '0';
        }
    }

    return sum;
}

bool compare(string a, string b) {
    if(a.length() != b.length()) {
        return a.length() < b.length();
    }
    else {
        int alen = getsum(a);
        int blen = getsum(b);

        if(alen != blen) {
            return alen < blen;
        }
        else {
            return a < b;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < N; i++) {
        cout << v[i] << endl;
    }
}
