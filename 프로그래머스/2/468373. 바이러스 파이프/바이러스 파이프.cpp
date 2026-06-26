#include <bits/stdc++.h>

using namespace std;
int N, K, result, infl;
int arr[11];
bool type[4];
vector<vector<pair<int, int>>> v;

int bfs() {
    set<int> st;
    st.insert(infl);
    
    for(int i = 0; i < K; i++) {
        int t = arr[i];
        
        queue<int> q;
        for(auto &iter : st) q.push(iter);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto &iter : v[node]) {
                if(iter.second == t && !st.count(iter.first)) {
                    st.insert(iter.first);
                    q.push(iter.first);
                }
            }
        }
    }
    
    return st.size();
}

void bt(int idx)  {
    if(idx == K) {
        result = max(bfs(), result);
        return;
    }
    
    for(int i = 1; i <= 3; i++) {
        if(type[i]) {
            arr[idx] = i;
            bt(idx+1);
        }
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    result = 0;
    N = n;
    K = k;
    infl = infection;
    memset(type, 0, sizeof(type));
    
    v.assign(n+1, vector<pair<int, int>>());
    
    for(auto &iter : edges) {
        if(iter[2] == 1) type[1] = true;
        else if(iter[2] == 2) type[2] = true;
        else type[3] = true;
    }
    
    for(auto &iter : edges) {
        v[iter[0]].push_back({iter[1], iter[2]});
        v[iter[1]].push_back({iter[0], iter[2]});
    }
    
    bt(0);
    
    return result;
}