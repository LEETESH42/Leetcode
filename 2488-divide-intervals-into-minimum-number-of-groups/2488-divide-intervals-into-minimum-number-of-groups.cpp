class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int> mp;
        for(auto it: intervals){
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        int ans=0,s=0;
        for(auto it: mp){
            s+=it.second;
            ans=max(ans,s);
        }
        return ans;
    }
};