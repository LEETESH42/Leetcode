class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>> q;
        q.push({startGene,0});
        unordered_map<string,int> mp;
        for(auto it:bank){
            mp[it]=1;
        }
        vector<char> vec={'A','C','G','T'};
        mp.erase(startGene);
        while(!q.empty()){
            auto x=q.front();
            q.pop();

            if(x.first==endGene){
                return x.second;
            }

            for(int i=0;i<8;i++){
                char original=x.first[i];
                for(auto ch:vec){
                    x.first[i]=ch;
                    if(mp.find(x.first)!=mp.end()){
                        q.push({x.first,x.second+1});
                        mp.erase(x.first);
                    }
                }
                x.first[i]=original;
            }

        }
        return -1;
    }
};