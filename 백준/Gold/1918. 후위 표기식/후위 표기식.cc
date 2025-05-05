#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
stack<int> st;
string s;

/*
 *      우선순위 연산자  *, /, + -
 *      * : 42, / : 47, + : 43, - : 45, ( : 40, ) : 41
 */

int priority(char ch) {
    if(ch == '(') return 3;
    else if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 2;
    return 0;
}

void solve() {
    for(int i = 0; i < s.size(); i++) {
        char stand = s[i];

        if(stand >= 65) {
            cout << stand;
            continue;
        }

        if(st.empty()) {        // 괄호, 더하기 빼기등 다양한
            st.push(stand);
        }
        else if(stand == '(') {     // 괄호는 바로 삽입
            st.push(stand);
        }
        else if(stand == ')') {
            while(st.top() != '(') {
                char tmp = st.top();
                cout << tmp;
                st.pop();
            }
            st.pop();
        }
        else {
            if(st.top() == '(') {       // top이 괄호일 경우 무조건 삽입
                st.push(stand);
            }
            else {
                while(!st.empty()) {
                    if(st.top() == '(') {
                        break;
                    }
                    else if(priority(st.top()) < priority(stand)) {      // top보다 현재 값이 큰 경우
                        break;
                    }
                    char tmp = st.top();
                    cout << tmp;
                    st.pop();
                }
                st.push(stand);
            }
        }
    }

    while(!st.empty()) {
        char tmp = st.top();
        cout << tmp;
        st.pop();
    }
}

void input() {
    cin >> s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}