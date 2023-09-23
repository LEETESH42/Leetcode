class Solution {
public:
    bool diff(string &f, string s){
        int d=0;
        for(int i=0;i<f.size();i++){
            if(f[i]!=s[i]){
                d++;
            }
        }
        if(d!=1){
            return false;
        }
        return true;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string,bool> vis;
        for(auto i:bank){
            vis[i]=0;
        }
        if(vis.find(endGene)==vis.end()){
            return -1;
        }
        if(vis.find(startGene)==vis.end()){
            bank.push_back(startGene);
        }

        unordered_map<string,vector<string>> adj;
        for(int i=bank.size()-1;i>0;i--){
            for(int j=i-1;j>=0;j--){
                if(diff(bank[i],bank[j])){
                    adj[bank[i]].push_back(bank[j]);
                    adj[bank[j]].push_back(bank[i]);
                }
            }
        }

        queue<pair<int,string>> q;
        q.push({0,startGene});
        while(!q.empty()){
            if(endGene==q.front().second){
                return q.front().first;
            }
            auto fr=q.front();
            q.pop();
            vis[fr.second]=true;
            for(auto it:adj[fr.second]){
                if(!vis[it]){
                    q.push({fr.first+1,it});
                }
            }
        } 
        return -1;
    }
};