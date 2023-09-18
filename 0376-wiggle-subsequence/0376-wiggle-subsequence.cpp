class Solution {
public:
    int solve(int ind, int prev, vector<int>& arr, vector<vector<int>>& dp){
        if(ind>=arr.size()){
            return 0;
        }

        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int pick=0;
        if(prev==-1 || (arr[ind]<0 && arr[prev]>0) || (arr[ind]>0 && arr[prev]<0)){
            pick=1+solve(ind+1,ind,arr,dp);
        }
        int notpi=solve(ind+1,prev,arr,dp);

        return dp[ind][prev+1]=max(pick,notpi);
    }

    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1;
        }

        vector<int> arr;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1])
                arr.push_back(nums[i]-nums[i-1]);
        }

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        int mx=solve(0,-1,arr,dp);
        return mx+1;
    }
};