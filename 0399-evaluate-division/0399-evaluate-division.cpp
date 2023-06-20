class Solution {
public:
    double dfs(map<string,vector<pair<string,double>>>& graph, map<string,int>& vis, string target, string curr){
        if(!graph.count(curr)){
            return INT_MAX;
        }
        if(curr==target){
            return 1;
        }
        for(auto i:graph[curr]){
            if(vis[i.first]){
                continue;
            }
            vis[i.first]=1;

            double currCost=i.second;
            double nextCost=dfs(graph, vis, target, i.first);

            vis[i.first]=0;
            if(nextCost!=INT_MAX){
                return (nextCost*currCost);
            }
        }
        return INT_MAX;
    }

    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        map<string,vector<pair<string,double>>> graph;
        for(int i=0;i<e.size();i++){
            graph[e[i][0]].push_back({e[i][1], v[i]});
            graph[e[i][1]].push_back({e[i][0], 1.00/v[i]});
        }

        vector<double> ans;
        map<string,int> vis;

        for(int i=0;i<q.size();i++){
            double cost=dfs(graph, vis, q[i][1],q[i][0]);

            if(cost==INT_MAX){
                ans.push_back(-1);
            }
            else{
                ans.push_back(cost);
            }
        }
        return ans;
    }
};