class Solution {
public:
    vector<int> vis;

    bool dfs(int node, vector<vector<int>>& graph){
        if(vis[node]==1){
            return false;
        }
        if(vis[node]==2){
            return true;
        }

        vis[node]=1;
        for(auto it:graph[node]){
            if(!dfs(it,graph)){
                return false;
            }
        }

        vis[node]=2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vis.resize(n);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]==2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};