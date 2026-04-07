#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int left, right;
};

const int INF = 1e9;
const int MAX = 100001;
const int D = 2000000;
const int MOD = 10007;
//int dx[] = {0, 0, 1, -1};
//int dy[] = {1, -1, 0, 0};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int N;
int arr[401];
vector<vector<int>> v(401);
int graph[21][21];

bool compare(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {        // 인접한 칸, 인접한 빈칸, 행, 열
    if(get<0>(a) == get<0>(b)) {
        if(get<1>(a) == get<1>(b)) {
            if(get<2>(a) == get<2>(b)) {
                return get<3>(a) < get<3>(b);
            }
            return get<2>(a) < get<2>(b);
        }
        return get<1>(a) > get<1>(b);
    }
    return get<0>(a) > get<0>(b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    int score[] = {0, 1, 10, 100, 1000};

    for(int i = 1; i <= N * N; i++) {
        cin >> arr[i];

        for(int j = 0; j < 4; j++) {
            int a;
            cin >> a;
            v[arr[i]].push_back(a);
        }
    }

    for(int l = 1; l <= N * N; l++) {
        int student = arr[l];
        vector<tuple<int, int, int, int>> tmp;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(graph[i][j] != 0) continue;
                int emptysq = 0;
                int likestudent = 0;

                for(int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                    if(graph[nx][ny] == 0) {
                        emptysq++;
                    }
                    else {
                        for(auto &iter : v[student]) {
                            if(graph[nx][ny] == iter) {
                                likestudent++;
                            }
                        }
                    }
                }
                tmp.push_back({likestudent, emptysq, i, j});
            }
        }
        sort(tmp.begin(), tmp.end(), compare);
        int x = get<2>(tmp[0]);
        int y = get<3>(tmp[0]);

        graph[x][y] = arr[l];
    }

    int answer = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int student = graph[i][j];
            int cnt = 0;
            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                for(auto &iter : v[student]) {
                    if(graph[nx][ny] == iter) {
                        cnt++;
                    }
                }
            }

            answer += score[cnt];
        }
    }

    cout << answer;
}