class Solution {
public:
    bool solve(int mask, int k, int curr, int sub, int n, vector<int>& nums, vector<int> &dp){
        if(k==0){
            if(mask==(1<<n)-1){
                return true;
            }
            return false;
        }
        
        if(curr==sub){
            return solve(mask,k-1,0,sub,n,nums,dp);
        }

        if(dp[mask]!=-1){
            return dp[mask];
        }

        bool ans=false;

        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                continue;
            }
            if(curr+nums[i]<=sub){
                int nmask=mask|(1<<i);
                ans=ans||solve(nmask,k,curr+nums[i],sub,n,nums,dp);
                nmask^=(1<<i);
            }
        }
        return dp[mask]=ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%k!=0){
            return false;
        }
        int sub=sum/k;
        vector<int> dp(1<<n,-1);
        return solve(0,k,0,sub,n,nums,dp);
    }
};