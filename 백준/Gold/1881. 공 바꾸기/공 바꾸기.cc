#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, answer;
int arr[101];
vector<int> v;

void solve() {
    vector<int> tmp(4);

    for(int i = 0; i < N; i++) {
        bool flag = false;

        for(auto it : v) {
            if(it == arr[i]) {
                flag = true;
                break;
            }
        }

        if(!flag) {
            if(v.size() >= 4) {     // 교환
                for(int j = 0; j < 4; j++) {
                    bool visited = false;

                    for(int k = i + 1; k < N; k++) {
                        if(v[j] == arr[k]) {
                            visited = true;
                            tmp[j] = k - i;
                            break;
                        }
                    }

                    if(!visited) {
                        tmp[j] = INF;
                    }
                }

                int val = -1;
                int idx = -1;
                for(int j = 0; j < 4; j++) {
                    if(tmp[j] > val) {
                        val = tmp[j];
                        idx = j;
                    }
                }

                v.erase(v.begin() + idx);
                v.push_back(arr[i]);
                answer++;
            }
            else {      // 삽입
                v.push_back(arr[i]);
                answer++;
            }
        }
    }

    cout << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}