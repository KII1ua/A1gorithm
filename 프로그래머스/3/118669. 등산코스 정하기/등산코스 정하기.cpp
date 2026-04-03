#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    const int INF = 1e9;
    vector<vector<pii>> v(n+1);
    vector<int> dist(n+1, INF);
    vector<int> dp(n+1, INF);
    
    for(int i = 0; i < paths.size(); i++) {
        int a = paths[i][0];
        int b = paths[i][1];
        int c = paths[i][2];
        
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    
    set<int> st;
    for(int i = 0; i < summits.size(); i++) {
        st.insert(summits[i]);
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    for(int i = 0; i < gates.size(); i++) {
        pq.push({gates[i], 0});
        dist[gates[i]] = 0;
    }
    
    while(!pq.empty()) {
        int node = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        
        if(st.find(node) != st.end()) continue;
        
        if(dist[node] < cost) continue;
        
        for(auto &iter : v[node]) {
            int nextnode = iter.first;
            int nextcost = max(cost, iter.second);
            
            if(dist[nextnode] > nextcost) {
                pq.push({nextnode, nextcost});
                dist[nextnode] = nextcost;
            }
        }
    }
    
    vector<int> answer;
    
    sort(summits.begin(), summits.end());
    
    pii ans = {INF, -1};
    
    for(auto &iter : summits) {
        if(dist[iter] < ans.first) {
            ans.first = dist[iter];
            ans.second = iter;
        }
    }
    
    answer.push_back(ans.second);
    answer.push_back(ans.first);
    
    return answer;
}