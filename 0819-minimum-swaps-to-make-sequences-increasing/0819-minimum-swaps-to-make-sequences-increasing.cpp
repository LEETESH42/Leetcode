class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int prev1, int prev2, vector<vector<int>>& dp, int isSwap){
        if(i==nums1.size()){
            return 0;
        }

        if(dp[i][isSwap]!=-1){
            return dp[i][isSwap];
        }

        int swapans=INT_MAX, noswap=INT_MAX;

        if(prev2<nums1[i] && prev1<nums2[i]){
            swapans=1+solve(nums1,nums2,i+1,nums2[i],nums1[i],dp,1);
        }

        if(prev1<nums1[i] && prev2<nums2[i]){
            noswap=solve(nums1,nums2,i+1,nums1[i],nums2[i],dp,0);
        }
        dp[i][isSwap]=min(swapans,noswap);
        return dp[i][isSwap];
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int prev1=-1;
        int prev2=-1;
        int n=nums1.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(nums1,nums2,i,prev1,prev2,dp,0);
    }
};