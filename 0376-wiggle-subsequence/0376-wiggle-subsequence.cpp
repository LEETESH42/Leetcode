class Solution {
public:
    int solve(int ind, vector<int>& nums, vector<vector<vector<int>>>& dp, int buy, int prev){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][prev][buy]!=-1){
            return dp[ind][prev][buy];
        }

        int profit=0;

        if(nums[ind]==nums[prev]){
            profit=solve(ind+1,nums,dp,buy,ind);
        }
        else{
            
            if(buy==1 && (nums[ind]>nums[prev])){
                profit=max(1+solve(ind+1,nums,dp,0,ind), solve(ind+1,nums,dp,1,prev));
            }
            if(buy==0 && (nums[ind]<nums[prev])){
                profit=max(1+solve(ind+1,nums,dp,1,ind), solve(ind+1,nums,dp,0,prev));
            }
        }
        return dp[ind][prev][buy]=profit;
    }

    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n,vector<int>(2,-1)));
        return max(solve(1,nums,dp,1,0)+1, solve(1,nums,dp,0,0)+1);
    }
};