long long dp[20001];
class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        map<int,int> mp;
        for(auto &a: nums){
            mp[a]++;
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;

        int sum=0,mod=1000000007;

        for(auto it:mp){
            if(it.first==0){
                continue;
            }

            for(int j=sum;j>=0;--j){
                for(int k=1;k<=it.second;++k){
                    dp[j+k*it.first]=(dp[j+k*it.first]+dp[j])%mod;
                }
            }
            sum+=it.second*it.first;
        }

        int ret=0;

        for(int i=l;i<=r;++i){
            ret=(ret+dp[i])%mod;
        }
        return 1LL*ret*(mp[0]+1)%mod;
    }
};