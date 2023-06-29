class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& r) {
        vector<int> adj[n];
        for(int i=0;i<r.size();i++){
            adj[r[i][0]].push_back(r[i][1]);
            adj[r[i][1]].push_back(r[i][0]);
        }

        int mx=0;
        queue<int> q;
        vector<int> v(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    int val=adj[i].size()+adj[j].size();
                    int check=1;

                    for(auto it:adj[i]){
                        if(it==j){
                            check=-1;
                            break;
                        }
                    }
                    if(check==-1){
                        val--;
                    }
                    mx=max(mx,val);
                }
            }
        }
        return mx;
    }
};