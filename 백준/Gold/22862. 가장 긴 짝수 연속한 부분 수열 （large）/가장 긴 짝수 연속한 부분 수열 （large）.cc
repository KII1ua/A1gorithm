// baekjoon 5636
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

    int N, K, a;
    vector<int> v;
    int start = 0;
    int end = 0;
    int cnt = 0;
    int currentlen = 0;
    int result = 0;

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }

    while(end < N) {
        if(v[end] % 2 == 0) {
            currentlen++;
            result = max(result, currentlen - cnt);
            end++;
        }
        else {
            if(cnt + 1 <= K) {
                cnt++;
                currentlen++;
                result = max(result, currentlen - cnt);
                end++;
            } else {
                if(end > start) {
                    if (v[start] % 2 == 1) {
                        cnt--;
                    }
                    start++;
                    currentlen--;
                }
                else {
                    start++;
                    end++;
                }
            }
        }
    }
    cout << result;
}