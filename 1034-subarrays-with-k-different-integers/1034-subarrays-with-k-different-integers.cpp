class Solution {
public:
    int solve(vector<int>& nums, int k){
        unordered_map<int,int> mp;
        int i=0,count=0;

        for(int j=0;j<nums.size();j++){
            mp[nums[j]]++;
            while(mp.size()>k){
                if(mp[nums[i]]==1){
                    mp.erase(nums[i]);
                }
                else{
                    mp[nums[i]]--;
                }
                i++;
            }
            count+=j-i+1;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};