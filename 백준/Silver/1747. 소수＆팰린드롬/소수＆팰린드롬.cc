#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 2000001;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
bool isPrime[MAX];

void Init() {
    isPrime[1] = true;

    for(int i = 2; i <= MAX; i++) {
        for(int j = i + i; j <= MAX; j += i) {
            isPrime[j] = true;
        }
    }
}

void solve() {
    Init();

    for(int i = N; i <= MAX; i++) {
        if(!isPrime[i]) {
            bool flag = false;
            string s = to_string(i);
            int left = 0;
            int right = s.size()-1;

            while(left < right) {
                if(s[left] == s[right]) {
                    left++;
                    right--;
                }
                else {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                cout << s;
                return;
            }
        }
    }
}

void input() {
    cin >> N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}