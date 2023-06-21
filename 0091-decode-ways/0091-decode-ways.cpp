class Solution {
public:
    int solve(int index, string s, vector<int>& dp){
        if(index==s.size()){
            return 1;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int ans=0;
        if(s[index]!='0'){
            ans+=solve(index+1,s,dp);
        }
        if(index+1<s.size() && (s[index]=='1' ||(s[index]=='2'&& s[index+1]<='6'))){
            ans+=solve(index+2,s,dp);
        }
        return dp[index]=ans;
    }

    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        return solve(0,s,dp);
    }
};