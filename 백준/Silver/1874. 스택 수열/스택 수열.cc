// baekjoon 24230
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, a;
    int tmp = 1;
    stack<int> answer;
    vector<char> v;
    bool visited = false;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a;
        while(tmp <= a) {
            answer.push(tmp);
            v.push_back('+');
            tmp++;
        }
        if(answer.top() == a) {
            answer.pop();
            v.push_back('-');
        }
        else {
            visited = true;
            break;
        }
    }
    if(visited == false) {
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << endl;
        }
    }
    else {
        cout << "NO";
    }
}