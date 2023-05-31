class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=10;
        int ans=9;
        int i=9;
        for(int in=2;in<=n;in++){
            ans*=i;
            dp[in]=dp[in-1]+ans;
            i--;
        }
        return dp[n];
    }
};