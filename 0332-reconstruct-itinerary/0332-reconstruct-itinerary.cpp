class Solution {
public:
    vector<string> ans;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    
    void dfs(string s){
        auto &edge=adj[s];
        while(!edge.empty()){
            string x=edge.top();
            edge.pop();
            dfs(x);
        }
        ans.push_back(s);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto t:tickets){
            string u=t[0];
            string v=t[1];
            adj[u].push(v);
        }

        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};