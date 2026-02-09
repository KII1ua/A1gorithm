#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 1001;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int T, k, n;

void solve(vector<int> &v1, vector<int> &v2) {
    vector<int> sum1, sum2;

    for(int i = 0; i < n; i++) {
        for(int j = n; j < 2 * n; j++) {
            sum1.push_back(v1[i] + v1[j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = n; j < 2 * n; j++) {
            sum2.push_back(v2[i] + v2[j]);
        }
    }

    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());

    int answer = 0;
    int diff = INF;

    for(int i = 0; i < sum1.size(); i++) {
        int value = k - sum1[i];

        int idx = lower_bound(sum2.begin(), sum2.end(), value) - sum2.begin();

        if(idx < sum2.size()) {
            int cur_sum = sum1[i] + sum2[idx];
            int df = abs(k - cur_sum);

            if(cur_sum == k) {
                answer = cur_sum;
                break;
            }

            if(diff > df) {
                diff = df;
                answer = cur_sum;
            }
            else if(diff == df) {
                answer = min(answer, cur_sum);
            }
        }

        if(idx > 0) {
            int cur_sum = sum1[i] + sum2[idx-1];
            int df = abs(k - cur_sum);

            if(cur_sum == k) {
                answer = cur_sum;
                break;
            }

            if(diff > df) {
                diff = df;
                answer = cur_sum;
            }
            else if(diff == df) {
                answer = min(answer, cur_sum);
            }
        }
    }

    cout << answer << endl;
}

void input() {
    cin >> T;

    while(T--) {
        cin >> k >> n;

        vector<int> v1, v2;

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2 * n; j++) {
                int a;
                cin >> a;

                if(i == 0) v1.push_back(a);
                else v2.push_back(a);
            }
        }

        solve(v1, v2);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}