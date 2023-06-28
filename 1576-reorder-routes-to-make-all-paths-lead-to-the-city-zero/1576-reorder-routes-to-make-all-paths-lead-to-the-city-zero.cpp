class Solution {
public:
    int ans=0;

    void dfs(vector<int>& vis, vector<pair<int,int>> adj[], int node){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it.first]){
                if(it.second){
                    ans++;
                }
                dfs(vis,adj,it.first);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& con) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:con){
            adj[it[0]].push_back({it[1],1});
            adj[it[1]].push_back({it[0],0});
        }
        vector<int> vis(n+1,0);
        dfs(vis,adj,0);
        return ans;
    }
};