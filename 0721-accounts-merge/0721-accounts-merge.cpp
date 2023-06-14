class DisjointSet{
public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++)
            parent[i]=i;
    }
    
    int findUpar(int node){
        if(node==parent[node]) return node;
        
        return parent[node]=findUpar(parent[node]);
    }
    
    void unionByRank(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v) return;
        else if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
    
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])==mp.end()){
                    mp[accounts[i][j]]=i;
                }
                else{
                     ds.unionByRank(mp[accounts[i][j]],i);
                }
            }
        }
        vector<string> mergeMail[n];
        
        for(auto it:mp){
            string mail=it.first;
            int node=it.second;
            mergeMail[ds.findUpar(node)].push_back(mail);
        }
        
        vector<vector<string>> ans;
        
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0) continue;
            string name=accounts[i][0];
            vector<string> mails;
            mails.push_back(name);
            sort(mergeMail[i].begin(),mergeMail[i].end());
            for(int j=0;j<mergeMail[i].size();j++){
                mails.push_back(mergeMail[i][j]);
            }
            ans.push_back(mails);
        }
        
        return ans;
        
    }
};