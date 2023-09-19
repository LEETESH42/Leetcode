class Solution {
public:
    int mod=1e9+7;
    int knightDialer(int n) {
        vector<long long> curr(10,1);
        vector<long long> next=curr;

        for(int i=2;i<=n;i++){
            next[0]=(curr[4]%mod + curr[6]%mod)%mod;
            next[1]=(curr[6]%mod + curr[8]%mod)%mod;
            next[2]=(curr[7]%mod + curr[9]%mod)%mod;
            next[3]=(curr[4]%mod + curr[8]%mod)%mod;
            next[4]=(curr[3]%mod + curr[9]%mod +curr[0]%mod)%mod;
            next[5]=0;
            next[6]=(curr[1]%mod + curr[7]%mod +curr[0]%mod)%mod;
            next[7]=(curr[2]%mod + curr[6]%mod)%mod;
            next[8]=(curr[1]%mod + curr[3]%mod)%mod;
            next[9]=(curr[4]%mod + curr[2]%mod)%mod;
            curr=next;
        }
        long long ans=0;
        for(int i=0;i<10;i++){
            ans+=next[i];
            ans%=mod;
        }
        return ans%mod;
    }
};