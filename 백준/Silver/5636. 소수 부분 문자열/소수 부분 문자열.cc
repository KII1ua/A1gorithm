// baekjoon 5636
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n";

bool compare(string a, string b) {
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

bool isPrime(string c) {
    ll num;
    num = stoi(c);

    if(num <= 1) {
        return false;
    }

    if(num % 2 == 0) {
        if(num == 2)
            return true;
        return false;
    }

    for(int i = 3; i < sqrt(num); i += 2) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s;

    while(true) {
        cin >> s;
        int tmp = 0;

        if(s == "0") {
            break;
        }

        for(int i = 1; i <= s.length(); i++) {
            for(int j = 0; j <= s.length() - i; j++) {
                if(s.substr(j, i).length() < 6) {
                    if (isPrime(s.substr(j, i)) && tmp < stoi(s.substr(j, i))) {
                        tmp = stoi(s.substr(j, i));
                    }
                }
            }
        }
        cout << tmp << endl;
    }
}