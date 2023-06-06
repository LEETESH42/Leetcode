class Solution {
public:
    bool dfs(int i, int vis[], int visPath[], int check[], vector<vector<int>>& graph){
        vis[i]=1;
        visPath[i]=1;

        check[i]=0;

        for(auto it:graph[i]){
            if(!vis[it]){
                if(dfs(it,vis,visPath,check,graph)==true){
                    check[i]=0;
                    return true;
                }
            }
            else if(visPath[it]){
                check[i]=0;
                return true;
            }
        }
        check[i]=1;
        visPath[i]=0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        int vis[n];
        int visPath[n];
        int check[n];

        for(int i=0;i<n;i++){
            vis[i]=0;
            visPath[i]=0;
            check[i]=0;
        }
        vector<int> safeNodes;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,visPath,check,graph);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]==1){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};