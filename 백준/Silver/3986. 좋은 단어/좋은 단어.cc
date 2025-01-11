// baekjoon 3968            unorder_map은 해시테이블 기반으로 insert, erase, find가 O(1)으로 수행된다.
#include <bits/stdc++.h>  // but map은 레드블랙트리를 기반으로 하여 실행 시간이 O(log N)이 된다.
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, cnt;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> s;

        if(s.length() % 2 == 0) {

            stack<char> st;

            for(int j = 0; j < s.length(); j++) {
                if(st.empty()) {
                    st.push(s[j]);
                }
                else {
                    if(st.top() != s[j]) st.push(s[j]);
                    else st.pop();
                }
            }
            if(st.empty()) cnt++;
        }
    }
    cout << cnt;
}
