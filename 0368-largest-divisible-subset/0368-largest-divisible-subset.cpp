class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n=nums.size();
        vector<int> dp(n,1),hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
        }

        int idx=0,mx=1;
        for(int i=1;i<n;i++){
            if(dp[i]>mx){
                mx=dp[i];
                idx=i;
            }
        }

        while(hash[idx]!=idx){
            ans.push_back(nums[idx]);
            idx=hash[idx];
        }
        ans.push_back(nums[idx]);
        return ans;
    }
};