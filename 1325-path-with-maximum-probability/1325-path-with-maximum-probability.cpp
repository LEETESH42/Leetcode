class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& suc, int st, int end) {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back({e[i][1], suc[i]});
            adj[e[i][1]].push_back({e[i][0], suc[i]});
        }

        priority_queue<pair<double,int>> pq;
        pq.push({1.0,st});

        vector<double> dist(n,INT_MIN);
        dist[st]=1;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            double d=it.first;
            int node=it.second;

            for(auto it: adj[node]){
                int adjNode=it.first;
                double ed=it.second;

                if(dist[adjNode]<d*ed){
                    dist[adjNode]=d*ed;
                    pq.push({dist[adjNode],adjNode});
                }

            }

        }

        if(dist[end]==INT_MIN){
            return 0.00000;
        }
        else{
            return dist[end];
        }

    }
};