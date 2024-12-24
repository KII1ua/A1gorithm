#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    int a, b;

    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> a >> b;
        cout << a + b << "\n";
    }
}