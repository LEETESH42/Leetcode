class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];

        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});

        vector<int> dist(n+1,1e9);
        dist[k]=0;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int currTime=it.first;
            int currNode=it.second;

            for(auto it:adj[currNode]){
                int nxt=it.first;
                int nxtT=it.second;

                if(currTime+nxtT<dist[nxt]){
                    dist[nxt]=currTime+nxtT;
                    pq.push({dist[nxt],nxt});
                }
            }
        }

        int mx=INT_MIN;
        for(int i=1;i<=n;i++){
            mx=max(mx,dist[i]);
        }
        return mx==1e9?-1:mx;
    }
};