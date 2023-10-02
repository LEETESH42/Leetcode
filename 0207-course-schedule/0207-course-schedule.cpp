class Solution {
public:
    bool dfs(int node, unordered_map<int,vector<int>>& graph, vector<int>& vis){
        vis[node]=1;

        for(auto &it: graph[node]){
            if(vis[it]==0){
                if(!dfs(it,graph,vis)){
                    return false;
                }
            }
            else if(vis[it]==1){
                return false;
            }
        }
        vis[node]=2;
        return true;
    }

    bool canFinish(int num, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>> graph;
        
        for(auto &p:pre){
            graph[p[0]].push_back(p[1]);
        }
        vector<int> vis(num,0);

        for(int i=0;i<num;i++){
            if(!vis[i]==2){
                continue;
            }
            if(!dfs(i,graph,vis)){
                return false;
            }
        }
        return true;
    }
};