class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> temp(primes.size(),0);
        vector<long long> dp(n+1,INT_MAX);

        dp[0]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<primes.size();j++){
                dp[i]=min(dp[i],primes[j]*dp[temp[j]]);
            }
            for(int j=0;j<primes.size();j++){
                if(primes[j]*dp[temp[j]]==dp[i]){
                    temp[j]++;
                }
            }
        }
        return dp[n-1];
    }
};