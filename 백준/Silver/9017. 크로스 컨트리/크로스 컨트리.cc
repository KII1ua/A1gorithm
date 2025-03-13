#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define endl "\n"

int T, N;
int arr[1001];
int teamcount[201];
int counttmp[201];
pii result[201];

void input() {
    cin >> T;

    while(T--) {
        cin >> N;

        memset(arr, 0, sizeof(arr));
        memset(teamcount, 0, sizeof(teamcount));
        memset(counttmp, 0, sizeof(counttmp));
        memset(result, 0, sizeof(result));
        int score = 1;

        for(int i = 0; i < N; i++) {
            int M;
            cin >> M;
            arr[i] = M;
            teamcount[M]++;
        }

        for(int i = 0; i < N; i++) {
            if(teamcount[arr[i]] == 6) {
                counttmp[arr[i]]++;
                if(counttmp[arr[i]] <= 4)
                    result[arr[i]].first += score;
                if(counttmp[arr[i]] == 5) {
                    result[arr[i]].second = score;
                }
                score++;
            }
        }

        int team = 1;
        int scores = int(1e9);

        for(int i = 1; i < 201; i++) {
            if(teamcount[i] != 6) continue;

            if(scores > result[i].first) {
                team = i;
                scores = result[i].first;
            }
            else if(scores == result[i].first) {
                if(result[team].second > result[i].second) {
                    team = i;
                }
            }
        }

        cout << team << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
