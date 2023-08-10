class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0;
        int i=0;
        long long mx=INT_MIN;

        unordered_map<int,int> mp;

        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            mp[nums[j]]++;

            if(j-i+1==k){
                if(mp.size()==k){
                    mx=max(mx,sum);
                }
                sum-=nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
        }
        if(mx==INT_MIN){
            return 0;
        }
        return mx;
    }
};