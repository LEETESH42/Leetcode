class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mp;

        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }

        priority_queue<pair<char,int>> pq;
        for(auto x:mp){
            pq.push(x);
        }

        string result="";

        while(!pq.empty()){
            auto large=pq.top();
            pq.pop();

            int len=min(repeatLimit, large.second);

            for(int i=0;i<len;i++){
                result+=large.first;
            }

            pair<char,int> sec;
            if(large.second-len>0){
                if(!pq.empty()){
                    sec=pq.top();
                    pq.pop();
                    result+=sec.first;
                }            
                else{
                    return result;
                }
                if(sec.second-1>0){
                    pq.push({sec.first,sec.second-1});
                }
                pq.push({large.first, large.second-len});
            }
        }
        return result;
    }
};