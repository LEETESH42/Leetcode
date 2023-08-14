class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        int curr=0;
        int count=0;

        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            if(curr==goal){
                count++;
            }
            if(mp.find(curr-goal)!=mp.end()){
                count+=mp[curr-goal];
            }
            mp[curr]++;
        }
        return count;

    }
};