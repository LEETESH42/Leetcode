class Solution {
public:
    int solve(int i, int k, vector<int>& nums, vector<int>& dp){
        int n=nums.size();
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        int len=0;
        int mx=-1e5;
        int mxans=-1e5;

        for(int j=i;j<min(i+k,n);j++){
            len++;
            mx=max(mx,nums[j]);
            int sum=len*mx + solve(j+1,k,nums,dp);
            mxans=max(mxans,sum);
        }
        return dp[i]=mxans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        // return solve(0,k,arr,dp);

        for(int ind=n-1;ind>=0;ind--){
            int len=0;
            int mx=-1e5;
            int mxans=-1e5;

            for(int j=ind;j<min(ind+k,n);j++){
                len++;
                mx=max(mx,arr[j]);
                int sum=len*mx+dp[j+1];
                mxans=max(mxans,sum);
            }
            dp[ind]=mxans;
        }
        return dp[0];
    }
};