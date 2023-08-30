class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;

        for(auto x:s){
            mp[x]++;
        }

        for(auto x: mp){
            pq.push({x.second,x.first});
        }

        string ans="";

        while(pq.size()>1){
            auto x=pq.top();
            pq.pop();
            auto y=pq.top();
            pq.pop();

            ans+=x.second;
            ans+=y.second;

            x.first--;
            if(x.first>0){
                pq.push(x);
            }   
            y.first--;
            if(y.first>0){
                pq.push(y);
            }
        }
        if(pq.size()){
            auto k=pq.top();
            if(k.first>1){
                return "";
            }
            else{
                ans.push_back(k.second);
            }
        }
        return ans;
    }
};