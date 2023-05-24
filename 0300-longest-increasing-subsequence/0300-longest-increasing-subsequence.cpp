class Solution {
public:
    int solve(int ind, int prev, int n, vector<int>& nums, vector<vector<int>>& dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        dp[ind][prev+1]=solve(ind+1,prev,n,nums,dp);
        if(prev==-1 || nums[ind]>nums[prev]){
            dp[ind][prev+1]=max(dp[ind][prev+1], 1+solve(ind+1,ind,n,nums,dp));
        }
        return dp[ind][prev+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        // int n=nums.size();
        // // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // // return solve(0,-1,n,nums,dp);
        // int ans=1;
        // vector<int> dp(n,1);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[i]>nums[j]){
        //             dp[i]=max(dp[i],dp[j]+1);
        //             ans=max(ans,dp[i]);
        //         }
        //     }
        // }
        // return ans;

        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return temp.size();

    }
};