class Solution {
public:
    int mod=1e9+7;
    long long dp[5004][10];
    vector<vector<int>> graph={{4,6},{8,6},{7,9},{8,4},{3,9,0},{},{1,7,0},{6,2},{1,3},{2,4}};

    long long solve(int ind, int n){
        if(n==0){
            return 1;
        }
        if(dp[n][ind]!=-1){
            return dp[n][ind];
        }
        long long ans=0;

        for(auto it:graph[ind]){
            ans+=solve(it,n-1);
            ans=ans%mod;
        }   
        return dp[n][ind]=ans%mod;
    }

    int knightDialer(int n) {
        if(n==1){
            return 10;
        }
        memset(dp,-1,sizeof(dp));
        long long ans=0;

        for(int i=0;i<=9;i++){
            if(i==5){
                continue;
            }
            ans+=solve(i,n-1)%mod;
            ans=ans%mod;
        }
        return ans%mod;
    }
};