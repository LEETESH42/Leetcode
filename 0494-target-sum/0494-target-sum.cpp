class Solution {
public:
    
    int solve(int ind, int sum, vector<int>& num, vector<vector<int>>& dp){
        if(ind==0){
            if(sum==0 && num[0]==0){
                return 2;
            }
            if(sum==0 || sum==num[0]){
                return 1;
            }
            return 0;
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        int non=solve(ind-1,sum,num,dp);
        int pi=0;
        if(num[ind]<=sum){
            pi=solve(ind-1,sum-num[ind],num,dp);
        }
        return dp[ind][sum]=(non+pi);
    }

    int findWays(vector<int> &num, int tar)
    {
        int n=num.size();
        vector<vector<int>> dp(n,vector<int>(tar+1,-1));
        return solve(n-1,tar,num,dp);
        
    }

    int countPartitions(int n, int d, vector<int> &arr) {
        // Write your code here.
        int totalSum=0;
        for(auto &itr:arr){
            totalSum+=itr;
        }
        if(totalSum-d<0 || (totalSum-d)%2){
            return false;
        }
        return findWays(arr,(totalSum-d)/2);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(),target,nums);
    }
};