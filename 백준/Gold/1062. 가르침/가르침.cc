// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N, K;
vector<string> v;
bool alphabet[26];
int result;


int canread() {
    int res = 0;

    for(int i = 0; i < N; i++) {
        bool readword = true;
        string word = v[i];

        for(int j = 0; j < word.length(); j++) {
            int idx = word[j] - 'a';

            if(alphabet[idx] == false) {
                readword = false;
                break;
            }
        }
        if(readword) {
            res++;
        }
    }
    return res;
}

void bt(int start, int end) {
    if(end == K) {
        result = max(result, canread());
        return;
    }

    for(int i = start; i < 26; i++) {
        if(alphabet[i] == true) continue;
        alphabet[i] = true;
        bt(i, end+1);
        alphabet[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s; v.push_back(s);
    }

    alphabet['a' - 'a'] = true;
    alphabet['n' - 'a'] = true;
    alphabet['t' - 'a'] = true;
    alphabet['i' - 'a'] = true;
    alphabet['c' - 'a'] = true;

    K = K - 5;

    if(K < 0) {
        cout << 0 << endl;
        return 0;
    }

    bt(0, 0);

    cout << result;
}
