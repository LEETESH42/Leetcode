class Solution {
public:
    int solve(string s, int ind,vector<int>& dp){
        if(ind==s.size()){
            return 1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int ans=0;
        if(s[ind]!='0'){
            ans+=solve(s,ind+1,dp);
        }
        if(ind+1<s.size() && (s[ind]=='1' || (s[ind]=='2' && s[ind+1]<='6'))){
            ans+=solve(s,ind+2,dp);
        }
        return dp[ind]=ans;
    }

    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(s,0,dp);
    }
};