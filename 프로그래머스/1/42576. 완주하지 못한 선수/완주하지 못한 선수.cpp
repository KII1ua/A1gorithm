#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    
    for(int i = 0; i < participant.size(); i++) {
        if(m.find(participant[i]) != m.end()) {
            m[participant[i]]++;
        }
        else m[participant[i]] = 1;
    }
    
    for(int i = 0; i < completion.size(); i++) {
        if(m.find(completion[i]) != m.end()) {
            m[completion[i]]--;
        }
    }
    
    for(auto it: m) {
        if(it.second != 0) {
            return it.first;
        }
    }
}