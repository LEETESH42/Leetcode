class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        vector<int> dp(n,0);

        for(auto it: nums){
            dp[it]+=it;
        }

        int prev=0;
        int curr=dp[1];

        for(int i=2;i<n;i++){
            int s=max(prev+dp[i], curr);
            prev=curr;
            curr=s;
        }
        return curr;
    }
};