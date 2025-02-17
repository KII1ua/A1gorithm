// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int arr[10];
int result;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;

    cin >> s;

    for(int i = 0; i < s.length(); i++) {
        int res = s[i] - '0';

        if(res == 6 || res == 9) {
            if(arr[6] < arr[9]) {
                arr[6]++;
            }
            else arr[9]++;
        }
        else arr[res]++;

    }

    for(int i = 0; i <= 10; i++) {
        result = max(arr[i], result);
    }

    cout << result;
}

