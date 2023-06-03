class Solution {
public:
    int solve(int itr, vector<int> adj[], vector<int>& informTime){
        int f=0;
        for(int i=0;i<adj[itr].size();i++){
            f=max(f, solve( adj[itr][i], adj, informTime));
        }
        f+=informTime[itr];
        return f;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<manager.size();i++){
            if(manager[i]==-1){
                continue;
            }
            adj[manager[i]].push_back(i);
        }
        int ans=solve(headID,adj,informTime);
        return ans;
    }
};