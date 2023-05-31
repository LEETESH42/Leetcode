class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        int curr=nums[i];
        int sum=nums[i];
        int index=i+1;

        while(index<nums.size() && nums[index]==curr){
            sum+=nums[i];
            index++;
        }

        while(index<nums.size() && nums[index]==curr+1){
            index++;
        }

        return dp[i]=max(sum+solve(index,nums,dp), solve(i+1,nums,dp));
    }

    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return solve(0,nums,dp);
    }
};