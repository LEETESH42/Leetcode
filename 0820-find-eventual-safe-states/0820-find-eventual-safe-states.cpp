class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> indegree(n,0);

        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                revGraph[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int cur=q.front();
            q.pop();
            ans.push_back(cur);
            
            for(auto it:revGraph[cur]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};