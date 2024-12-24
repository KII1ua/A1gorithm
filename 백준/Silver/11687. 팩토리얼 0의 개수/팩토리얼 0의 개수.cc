#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

bool compare(string a, string b) {
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

int check(int x) {
    int cnt = 0;
    for(int i = 5; i < x + 1; i *= 5) {
        cnt += (x / i);
    }
    return cnt;
}

int main() {
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);
    int M;
    int start = 1;
    int end = int(1e9);
    int tmp = 0;

    cin >> M;

    while(start <= end) {
        int mid = (start + end) / 2;

        tmp = check(mid);

        if(tmp >= M) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    if(check(start) == M) {
        cout << start;
    } else {
        cout << -1;
    }
}