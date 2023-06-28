class Solution {
public:
    void dfs(int start, int dest, vector<int>& curr, vector<vector<int>>& graph, vector<vector<int>>& ans){
        if(start==dest){
            ans.push_back(curr);
            return ;
        }

        for(auto i:graph[start]){
            curr.push_back(i);
            dfs(i,dest,curr,graph,ans);
            curr.pop_back();
        }

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> curr;
        curr.push_back(0);
        int n=graph.size();
        dfs(0,n-1,curr,graph,ans);
        return ans;
    }
};