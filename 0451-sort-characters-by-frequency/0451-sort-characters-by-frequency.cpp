class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        map<char,int> mp;

        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        string ans="";

        priority_queue<pair<int,char>> pq;

        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push({it->second,it->first});
        }

        while(pq.size()>0){
            char ch=pq.top().second;

            for(int i=0;i<pq.top().first;i++){
                ans+=ch;
            }
            pq.pop();
        }
        return ans;
    }
};